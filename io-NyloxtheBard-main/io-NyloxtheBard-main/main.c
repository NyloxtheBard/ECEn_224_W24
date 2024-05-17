#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib/buttons.h"
#include "lib/colors.h"
#include "lib/device.h"
#include "lib/display.h"
#include "lib/fonts/fonts.h"
#include "lib/log.h"

#define VIEWER_FOLDER "viewer/"
#define MAX_ENTRIES 8
#define MAX_FILE_NAME 100
#define MAX_TEXT_SIZE 400

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
 * array with all of the entries in the folder, up to 8 (MAX_ENTRIES), copying the strings from
 * d_name to the entries array. The function returns the number of entries it put into the entries
 * array.
 */
int get_entries(char *folder, char entries[][MAX_FILE_NAME]) { 
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
                //printf("Item name: %s\n", entry->d_name); 
            }
            
        }
        closedir(dir);   
        /*for (int i = 0; i < count; i++) {
            printf("%d: %s\n", i, entries[i]);
        }*/
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
    char filePath[MAX_FILE_NAME];
    snprintf(filePath, sizeof(filePath), "%s/%s", folder, file_name);
    
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL){
        printf("Failed to open file: %s\n", filePath);
        return;
    }
    //char *filePath = folder;
    //strcat(filePath, file_name);
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

int main(void) {

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
        if (button_center() == 0) {
            char *file_name = entries[selectedMenuItem];
            draw_file(VIEWER_FOLDER, file_name);
            draw_menu(entries, num_of_entries, selectedMenuItem);
        }
    }
    return 0;
}
