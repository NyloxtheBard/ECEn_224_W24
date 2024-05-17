#include <stdlib.h>
#include <string.h>

#include "image.h"

uint8_t create_bmp(Bitmap *dst, uint8_t *src) {
    int offset = 0;
    dst->img = NULL;

    // Copy in the bitmap file header
    memcpy(dst->file_header, src, BMP_FILE_HEADER_SIZE);
    offset += BMP_FILE_HEADER_SIZE;

    // Get filesize
    dst->file_size = (dst->file_header[5] << 8 * 3) | (dst->file_header[4] << 8 * 2) |
                     (dst->file_header[3] << 8 * 1) | (dst->file_header[2]);

    // Get start location of pixel data
    dst->pxl_data_offset = (dst->file_header[13] << 8 * 3) | (dst->file_header[12] << 8 * 2) |
                           (dst->file_header[11] << 8 * 1) | (dst->file_header[10]);

    // // Get DIB header data
    uint8_t dib_header_size = dst->pxl_data_offset - BMP_FILE_HEADER_SIZE;
    dst->dib_header = (uint8_t *)malloc((dib_header_size) * sizeof(uint8_t));
    memcpy(dst->dib_header, src + offset, dib_header_size);
    offset += dib_header_size;

    // Get image width
    dst->img_width = (dst->dib_header[7] << 8 * 3) | (dst->dib_header[6] << 8 * 2) |
                     (dst->dib_header[5] << 8 * 1) | (dst->dib_header[4]);

    // Get image height
    dst->img_height = (dst->dib_header[11] << 8 * 3) | (dst->dib_header[10] << 8 * 2) |
                      (dst->dib_header[9] << 8 * 1) | (dst->dib_header[8]);

    if (dst->img_height < 0) {
        dst->img_height *= -1;
    }

    // Get image data
    dst->pxl_data_size = dst->img_width * dst->img_height * 3;
    dst->pxl_data = malloc(sizeof(uint8_t) * dst->pxl_data_size);
    memcpy(dst->pxl_data, src + offset, dst->pxl_data_size);

    // Create copy of image data for reset
    dst->pxl_data_cpy = malloc(sizeof(uint8_t) * dst->pxl_data_size);
    memcpy(dst->pxl_data_cpy, dst->pxl_data, dst->pxl_data_size);

    return LOAD_SUCCESS;
}

void destroy_bmp(Bitmap *bmp) {
    free(bmp->dib_header);
    free(bmp->pxl_data);
    free(bmp->pxl_data_cpy);
}

void reset_pixel_data(Bitmap *bmp) {
    bmp->pxl_data = memcpy(bmp->pxl_data, bmp->pxl_data_cpy, bmp->pxl_data_size);
}

uint8_t *get_pxl_data(Bitmap *bmp) { return bmp->pxl_data; }

uint8_t *get_original_pxl_data(Bitmap *bmp) { return bmp->pxl_data_cpy; }

void remove_color_channel(Color color, Bitmap *bmp) {
    // Copy code from Image Lab here
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

void or_filter(Bitmap *bmp) {
    // Copy code from Image Lab here
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
