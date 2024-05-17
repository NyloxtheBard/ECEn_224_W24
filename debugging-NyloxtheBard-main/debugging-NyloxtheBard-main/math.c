#include <stdio.h>

#include "math.h"

// Below is a set of basic mathematical functions. Each function has a
// description of its intended purpose. You will need to rely on your
// trace debugging skills to diagnose the issues with each function.
// You may edit any of the functions' algorithms and data types in order
// to ensure the expected output matches that in the comments seen in the `main.c` file.

// For every debugging printf statement you make to correct these functions,
// COMMENT them out instead of erasing them so I can see your thought process
// behind resolving the functions.

// Intended function: return sum of a and b
uint16_t sum(uint16_t a, uint16_t b) { 
    //printf("Sum of %u and %u: %u\n", a, b, a + b);
    return a + b;
} // working properly

// Intended function: return difference between a and b
int16_t sub(int16_t a, int16_t b) { 
    //printf("Sub of %u and %u: %u\n", a, b, a - b);
    return a - b; 
} // should be uint? Should be int16 to keep the negatives proper, working properly

// Intended function: return product of a and b
uint16_t mult(uint16_t a, uint16_t b) { 
    //printf("Mult of %u and %u: %u\n", a, b, a * b);
    return a * b; 
} // Working properly

// Intended function: return a divided by b
double divide(int8_t a, int8_t b) { 
    //printf("Div of %d and %d: %f\n", a, b, (float)a /(float)b);
    return (double) a / (double) b;
    //return a / b; 
} // should throw an undefined error, do fractions, use a float, working properly

// Intended function: return the exponent of a^b power
uint32_t exponent(uint32_t a, uint32_t b) {
    uint32_t result = 1;
    for (uint32_t i = 0; i < b; i++) {
        result *= a;
    }
    //printf("Exponent of %u and %u: %u\n", a, b, result);
    return result;
} // ^ isn't supported by C++ this way, this is for logic gates

// Intended function: take an array of 5 uint8_t values and return the average
float avg_5(uint8_t vals[]) {
    float sum = 0;
    for (uint8_t i = 0; i < 5; i++) {
        sum += (float)vals[i];
    }
    //printf("Avg_5: %0.1f\n", sum / 5);
    return sum / 5;
}
