# I/O

## Experience Summary

### How many hours did it take to complete assignment?
4 hours

### What did you enjoy about this lab?
It was super cool to create a display on our rasberry pis and use the buttons to create an interactive machine with specified outputs

### What were the major challenges you had with this lab? Try to be as detailed as possible.
The hardest part of the lab for me was figuring out how to call the filepath for the draw_file function. The reason I struggled with this was due to the difficulty in combining the folder and file_name points in order to create a file path that I could then pass into the function. 

## Lab Specific Tasks

1. What are the file operation functions we use in this lab and what do they do?

The three file operation functions that I used in this lab were fopen(), fclose(), and fread(). They do the following:

fopen() - This operation function uses a input filename and a specified mode for opening it as either a read or write file. It also creates a filestream and stores it as a file pointer accordingly. 

fclose() - This operation function takes a specified file point as a input parameter in order to close the filestream that was created with the fopen() function. It is used after the fopen() function. 

fread() - This operation reads data from a specified input file pointer. It does this by taking a buffer to read data into, along with the size of the data and the length of the data, and the file pointer. The file pointer beforehand has to have the specified amount of characters/bytes, as that is the amount of characters/bytes that the fread() function can then read. 

2. What are the directory operation functions we use in this lab and what do they do?

The three directory operation functions that I used in this lab were the readdir(), opendir(), closedir(). They do the following:

readdir() - Takes a DIR pointer assigned by opendir() and then iterates through the linked-list, afterwhich it returns a struct object called a dirent pointer. This pointer contains all entries within the directory that the DIR pointer references. After the final file within this directory has been index, the readdir() function is set to return null.

opendir() - Takes a directory path and creates a DIR pointer that then holds its location for future use elsewhere in the code

closedir() - Takes the DIR pointer assigned in opendir() and closes the directory by releasing that pointer. 

3. What are the FILE and DIR pointers and how do they behave?

The DIR pointer is a special pointer specifically used to store the reference of a directory on the computer. It allows for the directory's location to be both viewed and the files within it to be interactable. This pointer is used through the usage of the directiory operation functions listed above

The FILE pointer acts as another special pointer that is used to both store and reference a specific file on the computer. It stores the current read and write location and action, which in turn allows for modification of its files and the ability to save them within the program. It also is used as a parameter to the file operation functions listed above, just as the DIR pointer is for the directory operation function. 

4. How does the FILE pointer differ from regular pointers in C?

Unlike most pointers that only point at a specified location within a file, the memory location, the FILE pointer points to the control structure, aka the read and write actions, the location, and the file data within the specified file. 
 
5. What are the risks associated with not closing a file after operations? Describe any experience you had with this during the lab.

By not closing a file after operations, it can cause for data corruption. If it is left open, it can also allow for a rogue operation to call the wrong reference pointer, along with potentially preventing other operations from running successfully.

6. What would happen if you try to open a non-existent directory using the DIR pointer?

It will throw an ENOENT error or something of that category to indicate that there was an attempt to open a non-existent directory through the usage of a DIR pointer. The pointer will also return NULL. 
