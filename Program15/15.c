/*
============================================================================
Name : 14.c
Author : Rahul Raman
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
                the monitor.
Date: 11th Sep, 2025.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
    // fd[0] -> read end
    // fd[1] -> write ends
    int fd[2];
    char buffer[20];
    pipe(fd);
    if(!fork()){
        close(fd[1]);
        read(fd[0],buffer,sizeof(buffer)); 
        printf("%s\n",buffer);
        
    }
    else{
        close(fd[0]); //parent is writing so we close the 
        write(fd[1],"HelloFrom15.c",14);
    }

    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/HandsOnList2/Program15$ cc 15.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/HandsOnList2/Program15$ ./a.out
HelloFrom15.c
============================================================================
*/
