/*
========================================================================================================
Name : 28.c
Author : Rahul Raman
Description : Write a program to change the existing message queue permission (use msqid_ds structure)
Date: 21 Sept, 2025
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');

    int msqid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds st;

    msgctl(msqid, IPC_STAT, &st);
    printf("Current access Permissions - %o\n", st.msg_perm.mode);

    st.msg_perm.mode = 0777;
    msgctl(msqid, IPC_SET, &st);
    msgctl(msqid, IPC_STAT, &st);
    printf("New access Permissions - %o\n", st.msg_perm.mode);
    return 0;
}
/*
========================================================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program28$ cc 28.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program28$ ./a.out
Current access Permissions - 666
New access Permissions - 777
========================================================================================================
*/