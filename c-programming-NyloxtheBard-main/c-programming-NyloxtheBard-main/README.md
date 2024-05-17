# Data

## Experience Summary

### How many hours did it take to complete assignment?
2.5 hours

### What did you enjoy about this lab?
I learned some new types of C commands and interesting ways to combine them. 

### What were the major challenges you had with this lab? Try to be as detailed as possible.
I accidentally deleted my README.md file near the end, so I had to figure out how to find that and redo the stuff that was lost. 

## Lab Specific Tasks

### A Simple C Program
1. What are the specific types of comments that exist in the C programming language?

There are two different types of comments, as follows:
// This is a single line comment
*/
This is a multi-line comment
*/


2. What is a compiler directive? When do they get used? 

A compiler directive is a statement that starts with a # sign. These directives help to govern the compilation process, determining which code is included, importing additional code, or offering conditional statements for compilation. Essentially, they function as in-code configurations for the compiler. While they are typically positioned at the top of the code, their placement can vary by directive. 

3. Define the following compiler directives and when they are used: `#define`, `#if`, `#else`, `#endif`.

#define sets macros holding specific unchanging values. It can be useful for fixed values in repetitive code, as it replaces every instance of a macro in the code with its assigned value.

#if is used with #else and #endif, it conditionally compiles code based on a true or false condition. If true, the code under #if is compiled. It is extrememly useful for selectively compiling code that you want to only run under specific conditions. 

#else is usually paired with #if, directs the compiler when the #if condition is not met, and compiles the code specified under #else instead. 

#endif is used with #if directives to mark the end of the code included within the conditional statement. 

4. Investigate other compiler directives that exist in C. Name two more and explain what they do and when they are used.

#pragma - a directive that provides a way for the user to give special instructions to the compiler. It is a mechanism for including additional information or directives that are compiler-specific.

#warning - a directive that generates a warning message during compilation. It allows the user to include custom warning messages in the code to alert about specific conditions or to provide documentation.

5. What is the `main()` function and why is it important in C programming?

The main() function is used to oversee the execution of other functions and code. When a program is launched, the main function is the first to compile, deciding what to initialize and is able to call other functions in the program.

6. What is a return value? Why are they used?

A return value is a value that a function provides as output after it finishes compiling. They are used as they are useful in many instances, whether in debugging code as it can indicate which function failed where, return data back to the calling code, and relay the outcome of the compiling of the program. 

7. Why does the `main()` function have a return value? Where can you access the return value of the `main()` function?

main() has a return value to tell the computer whether the program ran successfully or not, and if not, how it failed. Since return values get sent to the calling entity, they can typically be found by running either Bash or ZSH after running a program, and by typing in "echo $?".

8. Modify the `simple.c` file that you previously created (if you haven't yet, go read the lab webpage!). Modify your program to do the following:

- Add two functions with two different return value data types.

- Call those functions from within your main function and print the values to the terminal using `printf`.

[Simple C Program](./simple.c)

1. Compile your updated `simple.c` program above in `gcc`. Change the name of the executable to `simple`.  Compile the code into assembly instead of an executable. Google search, "gcc output assembly" to find your answer.

[Simple Assembly](./simple.s)

[Simple Binary](./simple)

10. Look at one of the commands in your `simple.s` file. Google it and try to figure out what it means and report your findings below.

I chose the ldr command in my 'simple.s' file, and from what I found the ldr command for my fun_numbers loads the value from the memory into the register, which in this case was the memory location of [sp, 12] into register w0.

### Data Types

1.  Read the [man page for `stdint.h`](https://man7.org/linux/man-pages/man0/stdint.h.0p.html). You'll find that a lot of extra info about standard C libraries are available there. List below the all the different types this library provides.

This is a list of the different types I found:
    int8_t
    int16_t
    int32_t
    uint8_t
    uint16_t
    uint32_t
    int64_t
    uint64_t
    int_least8_t 
    int_least16_t
    int_least32_t 
    int_least64_t 
    uint_least8_t 
    uint_least16_t
    uint_least32_t 
    uint_least64_t
    int_fast8_t 
    int_fast16_t
    int_fast32_t 
    int_fast64_t 
    uint_fast8_t 
    uint_fast16_t       
    uint_fast32_t 
    uint_fast64_t
    intptr_t
    uintptr_t
    intmax_t
    uintmax_t

12. Create a new file called `data.c`. This program should do the following. For each requirement, place a comment next to or above it so we know you have completed the required step:
    - Print out the hex equivalent of the `unsigned int`: 3735928559

    - Create a function that takes in a `uint8_t` as a parameter and prints `char` equivalent. Use it at least 3 times in your `main()`.
    
    - Use the `printf()` function at least once that has multiple formatting specifiers/placeholders.
    
    - Use at least 5 different format specifier types in 5 different `printf()` statements.
    
    - Use some format specifiers/placeholders in `printf()` in unexpected ways (i.e. pass in a `char` and format it with `%d`, or something similar). Your program must compile. In a comment next to or above this statement, explain the behavior and why you think it works that way.

[Data C](./data.c)

1.  Compile `data.c` into a binary called `data`.

[Data Binary](./data)

### Miscellaneous Questions
The following questions will require some research outside of this lab.

14. What is the biggest number an `int` can hold?

The biggest number an 'int' can hold is 2,147,483, 647. The only other way to get a higher number is through the usage of u_int type

15. Which is bigger, a `double` or a `float`?

'double' is much bigger than 'float', as it has a size of 64 bits and has about double the decimal places of 'float'

16. Arrange the following in data type size order (i.e., number of bytes): `int`, `double`, `long long`, `short`, `float`, `uint32_t`, `signed short`

Listed from smallest to biggest number of bytes:
'short', 'signed short', 'int', 'float', 'uint32_t', 'double', 'long long'
