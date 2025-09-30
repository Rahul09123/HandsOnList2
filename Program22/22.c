/*
============================================================================
Name        : 22.c
Author      : Rahul Raman
Description : Write a program to wait for data to be written into FIFO within 10 seconds,
                use select system call with FIFO.
Date: 29 Sept. 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>


int main() {
    int fd;
    fd_set readfds;
    struct timeval tv;
    char buf[100];
    int ret;

    // Create FIFO if not exists
    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY | O_NONBLOCK);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    printf("Waiting for data on FIFO for 10 seconds\n");

    ret = select(fd + 1, &readfds, NULL, NULL, &tv);
    if (ret == 0) {
        printf("Timeout! No data was written into FIFO under 10 seconds \n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            int n = read(fd, buf, sizeof(buf) - 1);
            if (n > 0) {
                buf[n] = '\0';
                printf("Received data: %s\n", buf);
            } else {
                printf("No data read (writer closed FIFO).\n");
            }
        }
    }

    close(fd);
    unlink("myfifo"); //removing fifo
    return 0;
}
/*
Output:
Terminal 1:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program22$ ./myfifo.out
Waiting for data on FIFO for 10 seconds
Received data: hello myfifo

Terminal 2:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program22$ echo "hello myfifo" > myfifo
*/