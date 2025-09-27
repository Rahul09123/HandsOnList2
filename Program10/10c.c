/*
========================================================================================================
Name : 10c.c
Author : Rahul Raman
Description : Write a separate program using sigaction system call to catch the following signals.
            c. SIGFPE
Date: 27 Sept, 2025
========================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigfpe(int sig) {
    printf("\nFloating-Point Exception caught! Signal number: %d. Exiting cleanly.\n", sig);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigfpe };

    printf("Handler installed. Program will now cause a floating-point exception...\n");

    int a = 1, b = 0;
    a = a / b;

    printf("This message will not be printed.\n");

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program10$ gcc 10c.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program10$ ./a.out
Handler installed. Program will now cause a floating-point exception...
Floating point exception
*/