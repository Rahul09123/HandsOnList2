/*
============================================================================
Name        : 23.c
Author      : Rahul Raman
Description : Write a program to print the maximum number of files can be 
            opened within a process and  size of a pipe (circular buffer). 
Date: 30 Sept. 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int pipeSize, fileSize;
    pipeSize = pathconf(".", _PC_PIPE_BUF);
    fileSize = sysconf(_SC_OPEN_MAX);
    printf("Size of pipe is = %d\n Max number of files that can be opened are %d\n", pipeSize, fileSize);
    return 0;
}
/*
Ouput:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program23$ ./23
Size of pipe is = 4096
 Max number of files that can be opened are 1048576
*/