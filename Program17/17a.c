/*
============================================================================
Name : 17a.c
Author : Rahul Raman
Description : Write a program to execute ls -l | wc.
                a. use dup
Date: 24th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];

    pipe(pipefd);
    
    if (fork() == 0) { 
        dup(pipefd[1]); // Duplicate write end of the pipe
        close(pipefd[0]); // Close unused read end for the child process
        execlp("ls", "ls", "-l", NULL); // Execute "ls -l"
    } else { 
        dup(pipefd[0]); // Duplicate read end of the pipe to stdin
        close(pipefd[1]); // Close unused write end for the parent process
        execlp("wc", "wc", NULL); // Execute "wc"
    }
    return 0;
}
/*
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program17$ cc 17a.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program17$ ./a.out
total 20
-rw-rw-r-- 1 asus asus   538 Sep 27 16:02 17a.c
-rwxrwxr-x 1 asus asus 16176 Sep 27 16:02 a.out
^Z
[1]+  Stopped                 ./a.out
*/