/*
========================================================================================================
Name : 34a.c
Author : Rahul Raman
Description : Write a program to create a concurrent server. 
            a. use fork 
Date: 30 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#define PORT 8088
#define BUFFER_SIZE 1000

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("Client: %s", buffer);
        send(client_sock, buffer, bytes, 0);
    }

    close(client_sock);
    exit(0);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)); //binding the server
    listen(server_sock, 3);
    printf("Server listening on port %d (fork)...\n", PORT);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);

        if (fork() == 0) { // Child process
            close(server_sock);
            handle_client(client_sock);
        } else {
            close(client_sock); 
        }
    }
    close(server_sock);
    return 0;
}
/*
Output:
s@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program34$ ./34a
Server listening on port 8088 (fork)...

*/
