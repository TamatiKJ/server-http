# client-http

C program to fetch a webpage

This is a simple HTTP client program that allows you to retrieve web pages from a server. It was part of the requirements for the completion of CSC 322 Networks and Distributed Programming at the University of Nairobi.

Prerequisites
Before running the program, ensure that you have the following:

A C compiler installed on your linux system (e.g., GCC)

To compile the HTTP client program, follow these steps:

Open a terminal or command prompt.

Navigate to the directory where you saved the "http_client.c" file using the cd command.

Execute the following command to compile the program:

gcc http_client.c -o http_client
This command uses the GCC compiler to compile the code and generates an executable file named "http_client".

Running the Program
To run the HTTP client program, follow these steps:

Execute the following command in your terminal:

./http_client

The program will prompt you to enter the server name or address.

YOu can find the address of a server using the nslookup command in linux as follows. 

nslookup example.com

Next, the program will prompt you to enter the path of the web page. Enter the path to an existing file on your machine, such as "/path/to/index.html". Make sure the file exists and is public or accessible by the server process.

The program will create a socket, connect to the specified server (in this case, the local machine), send an HTTP request, and print the received HTTP response.

Check the terminal or command prompt output to see the response from the server. It will display the content of the web page or any relevant response information.

Note
This http-client code is a basic example and may not handle all scenarios or security considerations. It is intended for educational purposes.





