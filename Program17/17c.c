/*
============================================================================
Name : 17a.c
Author : Rahul Raman
Description : Write a program to execute ls -l | wc.
                c. fcntl
Date: 24th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    int pipefd[2];
    pipe(pipefd);
    
    if (fork() == 0) { // Child process
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO); // Redirect stdout to the write end of the pipe
        close(pipefd[0]);
        close(pipefd[1]); // Close duplicate file descriptor
        execlp("ls", "ls", "-l", NULL); // Execute "ls -l"
    } else { // Parent process
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO); // Redirect stdin to the read end of the pipe
        close(pipefd[1]);
        close(pipefd[0]); // Close duplicate file descriptor
        execlp("wc", "wc", NULL); // Execute "wc"
    }
    
    return 0;
}
/*
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program17$ gcc 17c.c -o 17c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program17$ ./17c
total 60
-rw-rw-r-- 1 asus asus   899 Sep 27 16:03 17a.c
-rwxrwxr-x 1 asus asus 16176 Sep 27 16:05 17b
-rw-rw-r-- 1 asus asus   897 Sep 27 16:06 17b.c
-rwxrwxr-x 1 asus asus 16176 Sep 27 16:07 17c
-rw-rw-r-- 1 asus asus   688 Sep 27 16:07 17c.c
-rwxrwxr-x 1 asus asus 16176 Sep 27 16:02 a.out
^Z
[2]+  Stopped                 ./17c
*/