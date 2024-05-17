# Display

## Experience Summary

### How many hours did it take to complete assignment?
2

### What did you enjoy about this lab?
I thought it was fun getting to manipulate the output of the LCD screen, it was much more practical and hands on than what we have done before

### What were the major challenges you had with this lab? Try to be as detailed as possible.
Figuring out the correct syntax to call the image path was the only thing I struggled with, otherwise everything else was quite straightforward

## Lab Specific Tasks

### BCM2835 Library
1. What does the BCM2835 library do?

The BCM2835 allows access to the GPIO of the Raspberry PI, along with some other various functions, allowing us to interface with the HAT and the various buttons and the display within the C language.

2. How does the BCM2835 library differ from other GPIO libraries you might have come across?
   
THE BCM2835 library differes in the sense that it was specifically built for the HAT sensor used in our lab. OTher GPIO libaries control specificed modules or specific pins on a module. THis one just focuses on the HAT sensor in particular. 


### Drawing to Screen

3. Where is the origin of the LCD screen?

The origin of the screen is in the top left corner of the screen, starting at (0,0) ((x,y)).

4. How are the fonts passed into the `display_draw_string` function?

The fonts are passed in by reference using a pointer, which is noted by the *font in the display.h file. In order to use this function in the main.c file, I had to use &font.

5. What do you have to call before you can start drawing to the screen?

display_init(), as it initalizes all of the functions that control the screen, otherwise there would be segmentation fault and would be unable to edit and draw on the LCD screen. 

### Interacting with Buttons

6. What do you have to call before you can read from the buttons?

button_init(), same reasoning as question #5.

### Device Delay

8. Why do we add delays in our code? Which function accomplishes this and what library is it from?

We add delays in order to prevent the code from running inefficiently, as it would otherwise use more system resources too quickly. This in turn allows the code to run efficently. 

9. Can you think of any potential issues if the delay is set too long or too short in certain applications?

Too short of a delay time would cause the same issue as not having any delay at all, in another words the code would run ineffeciently due to using more system resources than necessary too quickly. Too long of a delay would cause the application to take longer than necessary to compile, and a user would have to wait longer than necessary to wait back for an output. 


### Miscellaneous

10. What is a `.gitignore` and how is it used?

'.gitignore' tells the Git code what files to ignore committing when you do a commit of your repo to Github. 

11. What command did you use to compile your code?

I used 'make' to compile my code, and 'sudo ./main' to run the program. 

