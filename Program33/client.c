/*
========================================================================================================
Name : client.c
Author : Rahul Raman
Description : Write a program to communicate between two machines using socket.
Date: 20 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8081

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *message = "Hello from client";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    read(sock, buffer, 1024);
    printf("Received from server: %s\n", buffer);

    close(sock);

    return 0;
}