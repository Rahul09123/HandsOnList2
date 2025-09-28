/*

============================================================================
Name : 3.c
Author : Rahul Raman
Description : Program to set system resource limit using setrlimit().
            This example sets a CPU time limit of 5 seconds.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit limit;

    limit.rlim_cur = 5;   // soft limit
    limit.rlim_max = 10;  // hard limit

    if (setrlimit(RLIMIT_CPU, &limit) == -1) {
        perror("setrlimit\n");
        exit(EXIT_FAILURE);
    }

    printf("CPU time limit set: soft=%ld sec, hard=%ld sec\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

    while (1) {
        // Just burn CPU cycles
    }

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program3$ gcc 3.c -o ./3.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program3$ ./3.out
CPU time limit set: soft=5 sec, hard=10 sec
CPU time limit exceeded (core dumped)
*/