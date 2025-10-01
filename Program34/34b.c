/*
========================================================================================================
Name : 34b.c
Author : Rahul Raman
Description : Write a program to create a concurrent server. 
            a. use pthread_creat
Date: 30 Sept, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8088
#define BUFFER_SIZE 1000

void *handle_client(void *arg) {
    int client_sock = *(int *)arg;
    free(arg);
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("Client: %s", buffer);
        send(client_sock, buffer, bytes, 0);
    }

    close(client_sock);
    pthread_exit(NULL);
}

int main() {
    int server_sock, *client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    pthread_t tid;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 5);
    printf("Server listening on port %d (threads)..\n", PORT);

    while (1) {
        client_sock = malloc(sizeof(int));
        *client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);

        if (pthread_create(&tid, NULL, handle_client, client_sock) != 0) {
            perror("Thread creation failed");
            free(client_sock);
        } else {
            pthread_detach(tid);
        }
    }

    close(server_sock);
    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program34$ ./34b
Server listening on port 8088 (threads)..

*/
