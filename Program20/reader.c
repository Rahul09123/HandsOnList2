/*
============================================================================
Name        : reader.c
Author : Rahul Raman
Description : Read a message from FIFO (named pipe).
Date : 30 Sept. 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main() {
    int fd;

    // Create FIFO if it doesn't exist
    mkfifo("myfifo", 0666);

    // Open FIFO for reading
    fd = open("myfifo", O_RDONLY);

    char buf[100];
    int n = read(fd, buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';  // null terminate
        printf("Reader: message %s", buf);
    } else {
        printf("Reader: no data received\n");
    }

    close(fd);
    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program20$ ./reader.out
Reader: message Hello from writer
*/
