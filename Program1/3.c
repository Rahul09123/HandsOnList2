/*
===========================================================================================================================
Name : 3.c
Author : Rahul Raman
Description : 1.  Write a separate program (for each time domain) to set a interval timer in 10sec and 
10micro second               
c. ITIMER_PROF 
Date: 28 Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handle_t(int signum) {
    write(STDOUT_FILENO, "Timer expired! (ITIMER_PROF)\n", 29);
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handle_t);

    timer.it_value.tv_sec = 1;   
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1); // keep process busy

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program1$ gcc 3.c -o ./3.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program1$ ./3.out
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)
*/
