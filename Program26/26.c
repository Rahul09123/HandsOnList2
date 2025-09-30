/*
========================================================================================================
Name : 26.c
Author : Rahul Raman
Description : Write a program to send messages to the message queue. Check $ipcs -q 
Date: 29 Sept, 2025.
========================================================================================================
*/

#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

struct msgbuf {
    long mtype;
    char mtext[1024];
};
int main(){
    key_t key;
    int msgid;
    struct msgbuf message;
    key = ftok(".",'a');
    
    msgid = msgget(key,0666 | IPC_CREAT);
    printf("Enter the message to put in the queue\n");
    fgets(message.mtext,strlen(message.mtext),stdin);

    msgsnd(msgid,message.mtext,strlen(message.mtext),message.mtype);
    printf("Message sent successfully\n");

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program26$ ./a.out
Enter the message to put in the queue
sending message inside message queue
Message sent successfully

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61051a52 0          asus       666        15           2   
*/