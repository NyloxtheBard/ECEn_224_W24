// This is a single line comment.

/* 
This is a multi-line comment.
Any text that is between the slash-star and
the star-slash will be ignored.
*/

#include <stdio.h>

int fun_number(){
    int funny = 10;
    return funny;
}

float multiplication(float a, float b){
    return a * b;
}

int main()
{
    printf("Hello, World!\n");
    printf("This is a funny number: %d\n", fun_number());
    printf("This is multiplication: %f\n", multiplication(10, 3.14));
    return 0;
}

