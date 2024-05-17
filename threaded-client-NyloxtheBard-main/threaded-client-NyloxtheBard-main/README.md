# Threaded Client

## Experience Summary

### How many hours did it take to complete assignment?
3 Hours

### What did you enjoy about this lab?
It is cool to be able to still interact with the program while it is still sending the image to the server. 

### What were the major challenges you had with this lab? Try to be as detailed as possible.
The information about how threading in the lab instructions wasn't great, and it made it harder for me to figure out what needed to be changed or implemented in this lab in order to get it working properly. 

## Lab Specific Tasks

### Creating a Thread

1. Why do we use threads?

We use threads to allow for the user to continue to interact with the program without waiting for the software that is loading to finish running. In previous iterations of this lab, we had to wait for the photo to finish uploading to the server before we could continue to interact with the menu. Now, we can interact and scroll through the menu, without waiting for the image to finish sending to the server. 

2. What does pthread stand for?

pthreads stands for POSIX THread, with POSIX being an acronym for Portable Operating System Interface, which is essentailly just the standards eneded for inter-operating system compatability. 

3. What function spawns a thread?

pthread_create() is the function that spawns a thread, which takes a pthread_t struct, a struct arguement for the pthread_create funciton, the function that is going to be called, along with any arguements to that function. It then creates the thread using this data. 

### Passing in Arguments to a Thread

4. What is the generic pointer called in C?

The generic pointer in C is the void * pointer. 


### Return Values from Threads

5. What function do we use to get return values from threads?

pthread_join() is the function that allows for us to get return values from threads. 

### Technical Debt

6. What is technical debt?

Technical debt is essentally referring to unpolished code, mainly upon the first iteration that needs to be refactored in order to be more efficient and operate better. 

7. Did you have any technical debt in this lab? What did you do to fix it?

No, but I did have to edit the functions that I currently had in order to make sure that the threading process was working properly. I have been pretty good at creating functions for the different processes listed throughout the labs and referencing them correctly. 
