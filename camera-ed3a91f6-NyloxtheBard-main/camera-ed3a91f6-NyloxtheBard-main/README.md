# Camera

## Experience Summary

### How many hours did it take to complete assignment?
3 Hours

### What did you enjoy about this lab?
I enjoyed utilizing the hardware for the camera, and getting to actually use the past labs to implement picture editing in real time

### What were the major challenges you had with this lab? Try to be as detailed as possible.
I had to rework how I was calling my entries, but otherwise I didn't struggle too much with this lab implementation

## Lab Specific Tasks

### Creating Large Buffers

1. What command is used to allocate memory?

malloc()

2. What library needs to be included in order to use this command?

<stdlib.h>

3. Where on the computer is the memory allocated? (Stack or Heap). Why is it stored there and not in the other place?

It allocates the memory in the Heap, as there is much more room within the heap for larger variables than Stack. 

4. What command is used to deallocate memory from the program? Why is it important to use this function?

free() is used to deallocate memroy, and it is important to use this function as it releases the allocated memory back to the system, which can prevent memory leaks.

5. Look at the **Memory Allocation in C** link in the **Explore More!** section at the bottom of the lab. List the other memory allocation functions discussed in the article and what they do differently than the commands described above.

calloc() - This function allocates memory for an array of elements of a certain size and initalizes all bytes to zero, which is the key difference to malloc(), as it does not do that. 

realloc() - This function is used to resize a previously allocated memory block, allowing it so that the size can be either increased or decreased. 

### Writing to a File

6. What do you need to do a file before you can write to it in C? What function is used for this?

Before you write to a file, you need to open it in C using "fopen()" function, which prepares the file essentially initalizing it so that it can be written to or read, or even both depending on the mode. 

7. What function writes to a file in C?

fprintf() is the function that allows to write formatted text to the file, while fwrite() is used to write binary data

8. What file mode allows for adding text to the end of the file?

"a" is the file mode that stands for append, this allows for text to be added to the end of the file

9. What mode indicates that you are writing to a binary file?

"wb" indicates that you are writing to a binary file. 
