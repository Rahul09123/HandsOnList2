/*
========================================================================================================
Name : 10a.c
Author : Rahul Raman
Description : Write a separate program using sigaction system call to catch the following signals.
            a. SIGSEGV
Date: 27 Sept, 2025
========================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigsegv(int sig) {
    printf("\nSegmentation Fault caught! Signal number: %d. Exiting cleanly.\n", sig);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigsegv };

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Handler installed. Program will now cause a segmentation fault...\n");

    int *ptr = NULL;
    *ptr = 42;

    printf("This message will not be printed.\n");

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program10$ gcc 10a.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program10$ ./a.out
Handler installed. Program will now cause a segmentation fault...

Segmentation Fault caught! Signal number: 11. Exiting cleanly.
*/