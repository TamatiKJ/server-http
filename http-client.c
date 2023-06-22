// HTTP server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main() {
    // Prompt the user for the server and path
    char server[100];
    char path[200];

    printf("Enter the server name or address (e.g., example.com or 192.168.0.1): ");
    scanf("%s", server);

    printf("Enter the path of the web page (e.g., /index.html): ");
    scanf("%s", path);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolve server IP address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, server, &(server_addr.sin_addr)) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, server);

    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Request sending failed");
        exit(EXIT_FAILURE);
    }

    // Receive and print the HTTP response
    char response[BUFFER_SIZE];
    memset(response, 0, sizeof(response));

    while (1) {
        int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("%s", response);
        memset(response, 0, sizeof(response));
    }

    // Close the socket
    close(sockfd);

    return 0;
}
