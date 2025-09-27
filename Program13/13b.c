/*
========================================================================================================
Name : 30a.c
Author : Rahul Raman
Description : Two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not. (Second).
Date: 27 Sept, 2025
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {

    int pid;
    printf("Enter pid of process to stop: \n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
    printf("Exiting current process (sender)\n");
    return (0);
}
/*
Output:
Terminal 1:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program13$ ./13.b
Enter pid of process to stop: 
9315
Sending SIGSTOP signal to process: 9315
SIGSTOP signal sent
Exiting current process (sender)


Terminal 2:

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program13$ ./13.b
Enter pid of process to stop: 
9315
Sending SIGSTOP signal to process: 9315
SIGSTOP signal sent
Exiting current process (sender)
*/