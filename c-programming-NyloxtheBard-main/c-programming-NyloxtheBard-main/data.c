#include <stdio.h>
#include <stdint.h>

void printChar(uint8_t value) {
    printf("Char equivalent: %c\n", value);
}

int main() {
    unsigned int num = 3735928559;

    // Print out the hex equivalent of the unsigned int: 3735928559
    printf("The Hexadecimal equivalent of 3735928559 is: 0x%X\n", num);

    // Use the printChar() function at least 3 times in main()
    printChar(65); 
    printChar(98); 
    printChar(120); 

    // Use the printf() function with multiple formatting specifiers/placeholders
    int a = 1000;
    int b = 243;
    printf("a: %d, b: %d\n", a, b);

    // Use at least 5 different format specifier types in 5 different printf() statements
    int c = 30;
    float d = 3.14;
    char e = 'E';
    char str[] = "Hello";
    uint32_t number = 4294967295;
    printf("Integer c: %d\n", c);
    printf("Float d (its pi): %f\n", d);
    printf("Character E: %c\n", e);
    printf("String stating: %s\n", str);
    printf("Number: %u\n", number);

    // Use format specifiers/placeholders in unexpected ways
    char ch = 'A';
    printf("A character that is manipulated: %d\n", ch); //It takes the character letter and essentially converts it to the decimal number, which in this case is 65

    return 0;
}