/*
========================================================================================================
Name : 10b.c
Author : Rahul Raman
Description : Write a separate program using sigaction system call to catch the following signals.
            b. SIGINT
Date: 27 Sept, 2025
========================================================================================================
*/
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include<string.h>

void handle_sigint(int sig) {
    printf("\nSIGINT signal (%d) caught! Ignoring. Press Ctrl+\\ to quit.\n", sig);
}

int main() {

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = handle_sigint;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("PID: %d. Waiting for SIGINT (Ctrl+C)...\n", getpid());

    while (1) {
        pause();
    }
    
    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program10$ gcc 10b.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program10$ ./a.out
PID: 15786. Waiting for SIGINT (Ctrl+C)...
^C
SIGINT signal (2) caught! Ignoring. Press Ctrl+\ to quit.
^\Quit (core dumped)
*/