/*
This is the driver file for the image library. All function definitions live in here
*/

#include <stdlib.h>
#include <string.h>

#include "image.h"

// --------------------------------------------------------------------------
// Image loading/saving functions
// --------------------------------------------------------------------------

uint8_t load_img(char *filepath, Bitmap *bmp) {
    // Opens file if it exists
    if (!(bmp->img = fopen(filepath, "r"))) {
        return LOAD_ERROR;
    }

    // Read in the bitmap file header
    fread(bmp->file_header, sizeof(uint8_t), BMP_FILE_HEADER_SIZE, bmp->img);

    // Get filesize
    bmp->file_size = (bmp->file_header[5] << 8 * 3) | (bmp->file_header[4] << 8 * 2) |
                     (bmp->file_header[3] << 8 * 1) | (bmp->file_header[2]);

    // Get start location of pixel data
    bmp->pxl_data_offset = (bmp->file_header[13] << 8 * 3) | (bmp->file_header[12] << 8 * 2) |
                           (bmp->file_header[11] << 8 * 1) | (bmp->file_header[10]);

    // Get DIB header data
    uint8_t dib_header_size = bmp->pxl_data_offset - BMP_FILE_HEADER_SIZE;
    bmp->dib_header = (uint8_t *)malloc((dib_header_size) * sizeof(uint8_t));
    fread(bmp->dib_header, sizeof(uint8_t), dib_header_size, bmp->img);

    // Get image width
    bmp->img_width = (bmp->dib_header[7] << 8 * 3) | (bmp->dib_header[6] << 8 * 2) |
                     (bmp->dib_header[5] << 8 * 1) | (bmp->dib_header[4]);

    // Get image height
    bmp->img_height = (bmp->dib_header[11] << 8 * 3) | (bmp->dib_header[10] << 8 * 2) |
                      (bmp->dib_header[9] << 8 * 1) | (bmp->dib_header[8]);

    // Get image data
    bmp->pxl_data_size = bmp->img_width * bmp->img_height * 3;
    bmp->pxl_data = (uint8_t *)malloc(sizeof(uint8_t) * bmp->pxl_data_size);
    fread(bmp->pxl_data, sizeof(uint8_t), bmp->pxl_data_size, bmp->img);

    // Create copy of image data for reset
    bmp->pxl_data_cpy = (uint8_t *)malloc(sizeof(uint8_t) * bmp->pxl_data_size);
    bmp->pxl_data_cpy = memcpy(bmp->pxl_data_cpy, bmp->pxl_data, bmp->pxl_data_size);

    // Close the file
    fclose(bmp->img);

    return LOAD_SUCCESS;
}

void reset_pixel_data(Bitmap *bmp) {
    bmp->pxl_data = memcpy(bmp->pxl_data, bmp->pxl_data_cpy, bmp->pxl_data_size);
}

uint8_t save_img(char *imgname, Bitmap *bmp) {
    FILE *save_img;
    if (!(save_img = fopen(imgname, "w"))) {
        fprintf(stderr, "Could not save the file with that name. Change the name and try again.\n");
        return SAVE_ERROR;
    }

    // Write BMP header
    fwrite(bmp->file_header, sizeof(uint8_t), BMP_FILE_HEADER_SIZE, save_img);

    // Write DIB header
    fwrite(bmp->dib_header, sizeof(uint8_t), bmp->pxl_data_offset - BMP_FILE_HEADER_SIZE, save_img);

    // Write pixel data
    fwrite(bmp->pxl_data, sizeof(uint8_t), bmp->pxl_data_size, save_img);

    // Close the file
    fclose(save_img);
    return SAVE_SUCCESS;
}

// --------------------------------------------------------------------------
// Image manipulation functions
// --------------------------------------------------------------------------

void remove_color_channel(Color color, Bitmap *bmp) {
    // To access the blue color in the xth pixel, you would index into pixel data by
    // x * 3. To access the green color in the xth pixel, you would index into the
    // pixel data by x * 3 + 1. To access the red color in the xth pixel, you would
    // index into the pixel data by x * 3 + 2.
    switch (color){
        case 0: //Blue_filter
            printf("Blue_filter\n");
            for (uint32_t pixel = 0; pixel < bmp->pxl_data_size/3; pixel++) {
                bmp->pxl_data[pixel*3] = bmp->pxl_data[pixel*3] & 0x00;
            }
            break;
        case 1: //Green_filter
            printf("Green_filter\n");
            for (uint32_t pixel = 0; pixel < bmp->pxl_data_size/3; pixel++) {
                bmp->pxl_data[pixel*3+1] = bmp->pxl_data[pixel*3+1] & 0x00;
            }
            break;
        case 2: //Red_filter
            printf("Red_filter\n");
            for (uint32_t pixel = 0; pixel < bmp->pxl_data_size/3; pixel++) {
                bmp->pxl_data[pixel*3+2] = bmp->pxl_data[pixel*3+2] & 0x00;
            }
            break;
    }
}
    /*for (int i = 0; i < bmp->pxl_data_size; i += 3) {
        switch (color) {
            case BLUE_CHANNEL:
                bmp->pxl_data[i] = 0;
                break;
            case GREEN_CHANNEL:
                bmp->pxl_data[i + 1] = 0;
                break;
            case RED_CHANNEL:
                bmp->pxl_data[i + 2] = 0;
                break;
        }
    }*/

void grayscale(Bitmap * bmp) {
        // Put code here //greyscale Filter
        printf("Greyscale_filter\n");
        for (uint32_t pixel = 0; pixel < bmp->pxl_data_size; pixel += 3) {
            uint8_t blue = bmp->pxl_data[pixel];
            uint8_t green = bmp->pxl_data[pixel + 1];
            uint8_t red = bmp->pxl_data[pixel + 2];
            uint8_t grey = red * 0.299 + blue * 0.114 + green * 0.587;
            bmp->pxl_data[pixel] = grey;
            bmp->pxl_data[pixel + 1] = grey;
            bmp->pxl_data[pixel + 2] = grey;
        }
    }

void or_filter(Bitmap * bmp) {
        // Put code here //Or Filter
        uint32_t currentRow = 0;
        uint32_t currentPixelCounter = 0;
        uint32_t width = bmp->img_width;
        uint32_t height = bmp->img_height;
        printf("Or_filter\n");
        for(uint32_t pixel = 0; pixel < bmp->pxl_data_size; pixel += 3){
            currentPixelCounter++;
            if(currentRow == 0){
                bmp->pxl_data[pixel] = bmp->pxl_data[pixel] | bmp->pxl_data[pixel + 3];
                bmp->pxl_data[pixel + 1] = bmp->pxl_data[pixel + 1] | bmp->pxl_data[pixel + 4];
                bmp->pxl_data[pixel + 2] = bmp->pxl_data[pixel + 2] | bmp->pxl_data[pixel + 5];
            } else if(currentRow == height){
                bmp->pxl_data[pixel] = bmp->pxl_data[pixel] | bmp->pxl_data[pixel + 3];
                bmp->pxl_data[pixel + 1] = bmp->pxl_data[pixel + 1] | bmp->pxl_data[pixel + 4];
                bmp->pxl_data[pixel + 2] = bmp->pxl_data[pixel + 2] | bmp->pxl_data[pixel + 5];
            } else {
                bmp->pxl_data[pixel] = bmp->pxl_data[pixel] | bmp->pxl_data[pixel + 3] | bmp->pxl_data[pixel + 3];
                bmp->pxl_data[pixel + 1] = bmp->pxl_data[pixel + 1] | bmp->pxl_data[pixel + 4];
                bmp->pxl_data[pixel + 2] = bmp->pxl_data[pixel + 2] | bmp->pxl_data[pixel + 5];
            }

            if(currentPixelCounter == width){
                currentRow++;
                currentPixelCounter = 0;
            }
        }
    }