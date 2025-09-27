/*
========================================================================================================
Name : 12.c
Author : Rahul Raman
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 27 Sept, 2025
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {

    int pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process (PID: %d), killing parent (PID: %d)\n", getpid(), getppid());
        kill(getppid(), SIGKILL); 
        sleep(2);
        printf("Child process (PID: %d) is now orphan, adopted by init (PID: %d)\n", getpid(), getppid());
    } else {
        sleep(10);
    }

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program12$ gcc 12.c -o 12.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program12$ ./12.out
Child process (PID: 10957), killing parent (PID: 10956)
Killed
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program12$ Child process (PID: 10957) is now orphan, adopted by init (PID: 2237)
*/
