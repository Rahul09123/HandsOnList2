/*
============================================================================
Name        : writer.c
Author: Rahul Raman
Description : Write a message into FIFO (named pipe).
Date: 30 Sept 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;

    // Create FIFO if it doesn't exist
    mkfifo("myfifo", 0666);

    // Open FIFO for writing
    fd = open("myfifo", O_WRONLY);

    char msg[] = "Hello from writer\n";
    write(fd, msg, sizeof(msg));
    printf("Writer: message %s", msg);

    close(fd);
    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program20$ ./writer.out
Writer: message Hello from writer
*/