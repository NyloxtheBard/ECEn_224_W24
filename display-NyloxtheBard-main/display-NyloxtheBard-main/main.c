#include <signal.h>

#include "lib/buttons.h"
#include "lib/colors.h"
#include "lib/device.h"
#include "lib/display.h"
#include "lib/fonts/fonts.h"
#include "lib/log.h"

/* DEFAULT COLORS */
#define BACKGROUND_COLOR WHITE
#define FONT_COLOR BLACK

// Makes sure to deinitialize everything before program close
void intHandler(int dummy) {
    log_info("Exiting...");
    display_exit();
    exit(0);
}

int main(void) {

    signal(SIGINT, intHandler);

    // Initialize the hardware here
    log_info("Starting...");
    display_init();
    buttons_init();
    delay_ms(1000);

    // Everythin inside this loop will repeat until 'Ctrl-C' is pressed in the terminal.
    while (true) {
        delay_ms(200);

        if (button_up() == 0){
            display_clear(WHITE);
            display_draw_rectangle(0, 0, 128, 20, GREEN, true, 2); //green rectangle top 20 pxls
            display_draw_rectangle(0, 108, 128, 128, RED, true, 2); //red rectangle btm 20 pxls
            //Forms the hashtag
            display_draw_line(54, 39, 54, 89, BLACK, 3); //left straight line
            display_draw_line(74, 39, 74, 89, BLACK, 3); //right straight line
            display_draw_line(39, 54, 89, 54, BLACK, 3); //top straight line
            display_draw_line(39, 74, 89, 74, BLACK, 3); //btm straight line
            //forms the hashtag
            display_draw_circle(64, 64, 30, YELLOW, false, 3); //yellow circle centered
        } else if (button_down() == 0){
            display_clear(WHITE);
        }else if (button_right() == 0){
            display_clear(WHITE);
            display_draw_string(32, 64, "Hello World!", &Font8, WHITE, BYU_BURGUNDY); //middle
            display_draw_string(32, 72, "Hello World!", &Font8, WHITE, BLUE);//1st btm
            display_draw_string(32, 80, "Hello World!", &Font8, WHITE, RED);//2nd btm
            display_draw_string(32, 56, "Hello World!", &Font8, WHITE, GREEN2);//1st top
            display_draw_string(32, 48, "Hello World!", &Font8, WHITE, AQUAMARINE);//2nd top
        } else if (button_left() == 0){
            display_clear(WHITE);
            display_draw_number(72, 72, 444, &Font8, WHITE, RED);
            display_draw_number(32, 32, 32, &Font8, WHITE, BLUE);
            display_draw_number(64, 64, 64, &Font8, WHITE, SILVER);
            display_draw_number(96, 96, 96, &Font8, WHITE, BYU_EGGPLANT);
            display_draw_number(100, 110, 128, &Font8, WHITE, CADET_BLUE);
            display_draw_number(0, 32, 99, &Font16, BLACK, RED);
            display_draw_number(32, 0, 66, &Font16, BLACK, BLUE);
            display_draw_number(0, 64, 8, &Font16, BLACK, SILVER);
            display_draw_number(50, 32, 123, &Font16, BLACK, BYU_EGGPLANT);
            display_draw_number(96, 0, 77, &Font16, BLACK, CADET_BLUE);

            
            display_draw_char(10, 10, 'a', &Font8, WHITE, BROWN3);
            display_draw_char(16, 10, 'e', &Font8, WHITE, BLACK);
            display_draw_char(32, 20, 'i', &Font8, WHITE, BROWN);
            display_draw_char(32, 30, 'o', &Font8, WHITE, GREEN2);
            display_draw_char(32, 40, 'u', &Font8, WHITE, ORANGE);
            display_draw_char(32, 50, 'a', &Font8, WHITE, RED);
            display_draw_char(32, 60, 'n', &Font8, WHITE, YELLOW);
            display_draw_char(32, 70, 'd', &Font8, WHITE, GREEN3);
            display_draw_char(32, 100, 's', &Font16, GREY, BLUE);
            display_draw_char(32, 116, 'y', &Font16, GREY, RED);
        } else if (button_center() == 0){
            display_clear(WHITE);
            display_draw_image("pic/byu_og.bmp");
        }

        // // Example of how to interact with a button
        // if (button_up() == 0) {
        // // Do something upon detecting button press

        //     while (button_up() == 0) {
        //         // Do something while the button is pressed
        //         delay_ms(1);
        //     }
        // }

        /* Write code to fufill lab requirements here*/
    }
    return 0;
}
