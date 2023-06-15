// HTTP client program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"  // Replace with the server IP address
#define SERVER_PORT 8080       // Replace with the server port

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &(server_addr.sin_addr)) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    char message[] = "Hello, server!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Message sending failed");
        exit(EXIT_FAILURE);
    }

    // Receive response from the server
    char response[4096];
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, sizeof(response) - 1, 0) < 0) {
        perror("Response receiving failed");
        exit(EXIT_FAILURE);
    }

    printf("Response from server: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}
