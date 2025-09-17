/*
============================================================================
Name : 14.c
Author : Rahul Raman
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
                the monitor.
Date: 11th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
    int fd[2];
    pipe(fd); // created a pipe
    char buffer[10] = "Hello";
    write(fd[1],buffer,sizeof(buffer)); //writing to the write end of the pipe
    read(fd[0],buffer,sizeof(buffer)); //reading to te read end of the pipe
    printf("buffer output %s\n",buffer);
    return 0;
}
/*
============================================================================
Output:
buffer output Helloasus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/HandsOnList2/Program14$ cc 14.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/HandsOnList2/Program14$ ./a.out
buffer output Hello
============================================================================
*/