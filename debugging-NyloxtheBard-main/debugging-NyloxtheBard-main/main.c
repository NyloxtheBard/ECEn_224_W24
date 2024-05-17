#include <stdint.h>
#include <stdio.h>

#include "math.h"

int main() {

    // You may only edit data types in this file. If your corrected function
    // in `math.c` works correctly, your variables should have the values
    // of the comments on the right.

    uint16_t sum_1 = sum(1, 2);             // = 3
    uint16_t sum_2 = sum(201, 68);          // = 269
    uint16_t sum_3 = sum(0xa4, 0b01100100); // = 264
    printf("Add: %d\n", sum_1);
    printf("Add: %d\n", sum_2);
    printf("Add: %d\n", sum_3); 

    int16_t sub_1 = sub(10, 8);    // = 2
    int16_t sub_2 = sub(90, 120);  // = -30
    int16_t sub_3 = sub(240, -17); // = 257
    printf("Sub: %d\n", sub_1);
    printf("Sub: %d\n", sub_2);
    printf("Sub: %d\n", sub_3); 


    uint16_t mult_1 = mult(7, 2);   // = 14
    uint16_t mult_2 = mult(45, 64); // = 2880
    uint16_t mult_3 = mult(3, 2);   // = 6
    printf("Mult: %d\n", mult_1);
    printf("Mult: %d\n", mult_2);
    printf("Mult: %d\n", mult_3); 

    double divide_1 = divide(10, 2); // = 5
    double divide_2 = divide(3, 0);  // = infinity
    double divide_3 = divide(1, 7);  // = 0.14285714285
    printf("Div: %d\n", (int)divide_1);
    printf("Div: %f\n", divide_2);
    printf("Div: %0.11f\n", divide_3); 

    uint32_t exp_1 = exponent(2, 0);  // = 1
    uint32_t exp_2 = exponent(5, 10); // = 9765625
    uint32_t exp_3 = exponent(2, 2);  // = 4
    printf("Exp: %u\n", exp_1);
    printf("Exp: %u\n", exp_2);
    printf("Exp: %u\n", exp_3); 

    uint8_t arr_1[] = {10, 11, 13, 15, 2};
    uint8_t arr_2[] = {100, 91, 127, 23, 8};
    uint8_t arr_3[] = {255, 255, 255, 255, 255};

    float avg_5_1 = avg_5(arr_1); // = 10.2
    float avg_5_2 = avg_5(arr_2); // = 69.8
    float avg_5_3 = avg_5(arr_3); // = 255
    printf("Sum: %0.1f\n", avg_5_1);
    printf("Sum: %0.1f\n", avg_5_2);
    printf("Sum: %.1f\n", avg_5_3);

    // Print all the variables below to ensure that they are the correct value.

    return 0;
}
