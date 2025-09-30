/*
============================================================================
Name : 4.c
Author : Rahul Raman
Description : Program to measure execution time of 100 getppid() system calls
              using the CPU timestamp counter (RDTSC).
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static __inline__ uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}


int main() {
    uint64_t start, end;
    int i;

    start = rdtsc();
    
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // Record ending timestamp
    end = rdtsc();

    printf("Total cycles taken for 100 getppid() calls: %llu\n",(unsigned long long)(end - start));
    printf("Average cycles per getppid(): %llu\n",(unsigned long long)(end - start) / 100);

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program4$ gcc 4.c -o ./4.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program4$ ./4.out
Total cycles taken for 100 getppid() calls: 63126
Average cycles per getppid(): 631
*/