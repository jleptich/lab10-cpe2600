/**
 * File: recv_signal.c
 * Modified by: Joseph Leptich
 * 
 * Brief summary of program:
 * created a program that reads a value from sigqueue, that is queued by another program.
 * Uses a fork to execute the sender file in code without having to use run it in cli
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
//handler file that prints out the recieved number
void handler(int sig, siginfo_t *info, void *ucontext){
    printf("\n\nThe value recieved is: %d\n\n",info->si_value.sival_int);
    return;
}


 int main(){
    sleep(1);
    //printf("PID: %d",getpid());

    //sets up the sigaction struct
    struct sigaction act;
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);

    //creating a fork so the send executable can be ran in code, must be ran in child otherwise takes over this program
    int pid1 = fork();
    if(pid1 == 0){
        char buff[32];
        snprintf(buff, sizeof(buff),"%d",getppid());
    char *args[] = {"sender",buff,NULL};
    char *envp[] = {NULL};
    execve("./send", args, envp);
    }
    //does nothing
    while(1){
        sleep(1);
        //printf("Something\n");

    }

    return 0;

 }
