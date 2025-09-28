/*
===========================================================================================================================
Name : 1.c
Author : Rahul Raman
Description : 1.  Write a separate program (for each time domain) to set a interval timer in 10sec and 
10micro second               
c. ITIMER_REAL
Date: 28 Sept, 2025.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handle_t(int signum) {
    printf("Timer expired! (ITIMER_REAL)\n");
}

int main() {

    struct itimerval timer;
    signal(SIGALRM, handle_t);
    
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);
    while (1);

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program1$ ./1.out
Timer expired! (ITIMER_REAL)
Timer expired! (ITIMER_REAL)
Timer expired! (ITIMER_REAL)
*/