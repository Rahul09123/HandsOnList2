/*
========================================================================================================
Name : 31.c
Author : Rahul Raman
Description :  Write a program to create a semaphore and initialize value to the semaphore. 
                a. create a binary semaphore 
                b. create a counting semaphore 
Date: 30 Sept, 2025
========================================================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<sys/ipc.h>

struct semun{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main(){

    key_t key;
    struct semun arg;
    key = ftok(".",'a');
    int semid = semget(key,1,0666 | IPC_CREAT); //creates a semaphore set
    int choice;
    printf("Enter 1 for Binary Semaphone\n Enter 2 for Counting Semaphore\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("Creating Binary Semaphore\n");
        arg.val = 1;
    }
    else if(choice == 2){
        printf("Creating Counting Semaphore\n");
        arg.val = 3;
    }
    else{
        printf("Invalid Choice\n");
        exit(1);
    }

    semctl(semid,0,SETVAL,arg);
    return 0;
}