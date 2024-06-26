#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include "lib/client.h"
#include "lib/buttons.h"
#include "lib/camera.h"
#include "lib/colors.h"
#include "lib/device.h"
#include "lib/display.h"
#include "lib/fonts/fonts.h"
#include "lib/image.h"
#include "lib/log.h"

#define VIEWER_FOLDER "viewer/"
#define MAX_ENTRIES 8
#define MAX_TEXT_SIZE 400
#define MAX_FILE_NAME 100

// Colors — Feel free to change these to fit your preference
#define BACKGROUND_COLOR WHITE
#define FONT_COLOR BLACK
#define SELECTED_BG_COLOR BYU_BLUE
#define SELECTED_FONT_COLOR BYU_LIGHT_SAND

// Makes sure to deinitialize everything before program close
void intHandler(int dummy) {
    log_info("Exiting...");
    display_exit();
    exit(0);
}

/*
 * Takes in a folder, reads the contents of the folder, filtering out any files that do not end with
 * .log or .bmp. This function should check to make sure the folder exists. It fills in the entries
 * array with all of the entries in the folder, up to 8 (MAX_ENTRIES). The function returns the
 * number of entries it put into the entries array.
 */
int get_entries(char *folder, char entries[][MAX_FILE_NAME]) {
    // Copy your code from the previous lab
    DIR *dir;
    int count = 0;
    dir = opendir(folder);

    if (folder == NULL){
        printf("The folder is empty");
        return -1;
    } else {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL && (count < MAX_ENTRIES)) {
            if (strstr(entry -> d_name, ".log") != NULL || strstr(entry -> d_name, ".bmp") != NULL) {
                strncpy(entries[count], entry -> d_name, MAX_FILE_NAME - 1);
                entries[count][MAX_FILE_NAME - 1] = '\0'; //used to ensure null is being terminated
                count++;
                
            }
            
        }
        closedir(dir);   
        //printf("count: %d\n", count);
        return count;    
    }
}

/*
 * Draws the menu of the screen. It uses the entries array to create the menu, with the num_entries
 * specifying how many entries are in the entries array. The selected parameter is the item in the
 * menu that is selected and should be highlighted. Use BACKGROUND_COLOR, FONT_COLOR,
 * SELECTED_BG_COLOR, and SELECTED_FONT_COLOR to help specify the colors of the background, font,
 * select bar color, and selected text color.
 */
void draw_menu(char entries[][MAX_FILE_NAME], int num_entries, int selected) {
    // Copy your code from the previous lab
    display_clear(BACKGROUND_COLOR);
    for (int i = 0; i < num_entries; i++) {
        char *menuText = entries[i];
        display_draw_string(8, i*16+4, menuText, &Font8, BACKGROUND_COLOR, FONT_COLOR); 
        if (i == selected) {
            display_draw_rectangle(0, i*16, 128, i*16+14, SELECTED_BG_COLOR, true, 1);
            display_draw_string(8, i*16+4, menuText, &Font8, SELECTED_BG_COLOR, SELECTED_FONT_COLOR); 
        }
    }
}


/*
 * Displays an image or a log file. This function detects the type of file that should be draw. If
 * it is a bmp file, then it calls display_draw_image. If it is a log file, it opens the file, reads
 * 100 characters (MAX_TEXT_SIZE), and displays the text using display_draw_string. Combine folder
 * and file_name to get the complete file path.
 */
void draw_file(char *folder, char *file_name) {
    // Copy your code from the previous lab
    char filePath[MAX_FILE_NAME];
    snprintf(filePath, sizeof(filePath), "%s/%s", folder, file_name);
    
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL){
        printf("Failed to open file: %s\n", filePath);
        return;
    }
    if (strstr(file_name, ".bmp") != NULL){
        display_draw_image(filePath);
        delay_ms(2000);

    } else if (strstr(file_name, ".log") != NULL) {
        char logFile[MAX_TEXT_SIZE] = "\0";
        fread(logFile, 1, MAX_TEXT_SIZE, fp);
        display_clear(WHITE);
        display_draw_string(5, 10, logFile, &Font8, BACKGROUND_COLOR, FONT_COLOR);
        delay_ms(2000);
    }
    fclose(fp);

}

void send_data(const Config *config) {
    int socket = client_connect(config);
    client_send_image(socket, config);
    client_receive_response(socket);
    client_close(socket);

}

void pic_process() {
    uint8_t *pic_buff = malloc(sizeof(uint8_t) * IMG_SIZE);
    camera_capture_data(pic_buff, IMG_SIZE);
    Bitmap *bmp_point = malloc(sizeof(Bitmap));
    create_bmp(bmp_point, pic_buff);
    camera_save_to_file(pic_buff, IMG_SIZE, "viewer/doorbell.bmp");

    //Initializes the Config struct with the photo data
    Config photo_data;
    photo_data.payload = pic_buff;
    photo_data.payload_size = sizeof(uint8_t) * IMG_SIZE;
    photo_data.port = "2240";
    photo_data.host = "ecen224.byu.edu";
    photo_data.hw_id = "DD7B3E403";

    send_data(&photo_data);



    free(pic_buff);

    display_draw_image_data(get_pxl_data(bmp_point), DISPLAY_WIDTH, DISPLAY_HEIGHT);
    while (true) {
        delay_ms(200);

        if (button_center() == 0) {

            break;
        } else if (button_right() == 0) {
            reset_pixel_data(bmp_point);
            remove_color_channel(RED_CHANNEL, bmp_point);
        } else if (button_left() == 0) {
            reset_pixel_data(bmp_point);
            remove_color_channel(BLUE_CHANNEL, bmp_point);
        } else if (button_up() == 0) {
            reset_pixel_data(bmp_point);
            remove_color_channel(GREEN_CHANNEL, bmp_point);
        } else if (button_down() == 0) {
            reset_pixel_data(bmp_point);
            or_filter(bmp_point);
        }

        display_draw_image_data(get_pxl_data(bmp_point), DISPLAY_WIDTH, DISPLAY_HEIGHT);

    }

    destroy_bmp(bmp_point);
    free(bmp_point);

}

int main(void) {
    // Copy your code from the previous lab
    signal(SIGINT, intHandler);

    log_info("Starting...");

    // Use this to fill in with entries from the directory
    char entries[MAX_ENTRIES][MAX_FILE_NAME];

    // TODO: Initialize the hardware

    display_init();
    buttons_init();

    // TODO: Get directory contents using get_entries function

    int num_of_entries = get_entries(VIEWER_FOLDER, entries);

    // TODO: Draw menu using draw_menu function
    int selectedMenuItem  = 0;
    draw_menu(entries, num_of_entries, 0);
    
    while (true) {
        delay_ms(200);

        // TODO: Put button logic here
        if (button_down() == 0) {
            selectedMenuItem = (selectedMenuItem == num_of_entries - 1) ? 0 : selectedMenuItem + 1;
            draw_menu(entries, num_of_entries, selectedMenuItem);
        }
        // Example of how to interact with a button
        if (button_up() == 0) {
            // Do something upon detecting button press
            selectedMenuItem = (selectedMenuItem == 0) ? num_of_entries - 1 : selectedMenuItem - 1;
            draw_menu(entries, num_of_entries, selectedMenuItem);
        }
        while (button_up() == 0) {
            // Do something while the button is pressed
            selectedMenuItem = (selectedMenuItem == 0) ? num_of_entries - 1 : selectedMenuItem - 1;
            draw_menu(entries, num_of_entries, selectedMenuItem);
            delay_ms(200);
        }
        if (button_right() == 0) {
            char *file_name = entries[selectedMenuItem];
            draw_file(VIEWER_FOLDER, file_name);
            draw_menu(entries, num_of_entries, selectedMenuItem);
        }
        if (button_center() == 0) {
            display_clear(BACKGROUND_COLOR);
            display_draw_string(42, 40, "SAY", &Font20, WHITE, BYU_BURGUNDY); //SAY CHEESE message before photo
            display_draw_string(16, 62, "CHEESE!", &Font20, WHITE, BLUE);
            pic_process();
            num_of_entries = get_entries(VIEWER_FOLDER, entries);
            //printf("numentries: %d\n", num_of_entries);
            draw_menu(entries, num_of_entries, selectedMenuItem);
        }
    }
    return 0;
}
