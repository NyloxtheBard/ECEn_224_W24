# Client

## Experience Summary

### How many hours did it take to complete assignment?
2 Hours

### What did you enjoy about this lab?
I enjoyed implementing the send image function and being able to view it on a website that is locally hosted BYU.

### What were the major challenges you had with this lab? Try to be as detailed as possible.
The only major issue I had was that for my main.c file, for whatever reason even though I had included the stdint library within my image.h file that was imported, it wasn't recognizing it so I had to call it seperately into my main file so that my uint8_t functions and the related functions worked as well. Other than that, I did have a small issue calling the correct sizes in the client_send_image function, but that was quickly resolved with some experimentation. 

## Lab Specific Tasks

### Config Struct
1. What is the purpose of a `struct` in C? How do we use the struct in this lab?

The purpose of 'struct' in C is to group similar elements or variables together within the program. It is useful as it allows a variety of things to be accessed by a single pointer, and it was used in this lab in particular to group the data that I wanted to upload to the server client. 

2. Look at the implementation of the `client_connect()` function. What structs are used there? While you are not expected to know the particulars of how the socket creation works, what purpose `addrinfo` struct serve?

In the 'client_connect()', there are four different structs that are used. The first is the Config struct that I created to hold the data that I wanted to send to the server client. The next three are all addrinfo structs which are named hints, result, and rp. These contain information about the protocol, socket type, address, and the address length, along with a few other data values that are needed to connect to the server. These structs are used to determine how the 'client_connect()' function sets up the socket, along with where the server is located and the required protocols to connect it. 

### Network Socket
3. What data type is used to represent a socket in C?

The data type 'int' is used to represent a socket in C, as it serves as a file descriptor that identifies the socket.

4. What does a file descriptor do?

A file descriptor is an identifier/reference that the OS uses to assign to a file when that particular file is opened. It is useful in the sense that it allows for the program to interact with different files, sockets, and other input and output resources. 

5. List some similarities and differences between writing to a file and writing to a socket?

Similarities: Both use file descriptors, along with both needing to be open and closed when used. They also both have helper functions, such as write() for files and send() for sockets that allow for data to be easily written to them. They also both use buffers to store data that is to be written. 

Differences: The nature of how both of these are used is different, as files are often used as a storage operation and sockets are used as a network operation. Sockets also require protocols to follow and standards, while files do not. Another difference is that sockets need to be opened using structs that contain multiple dtat types and information sets, while files just need to be opened in a specified mode and require the reference to the file itself. 

### Sending Data

6. What command is used to send data over a network socket? What parameters does it take and what do they mean?

'send()' is the command used to send data over a network socket. It needs four parameters, the first being the socket descriptor, that referes to the socket used to send data. The second is the buffer that contains the data that is being sent. The third is length of the message in bytes that is being sent. The final parameter is the flags that are specifying the type of message transmission. 
