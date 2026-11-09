/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */

 #include <stdio.h>
 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>

 void handler(int sig, siginfo_t *info, void *ucontext){
    printf("\n\nProcess identifer of sender: %d\n\n",info->si_pid);
    return;
 }
 int main(){
    //have to setup the act struct in order ot use sigaction properly
    struct sigaction act; 
    act.sa_sigaction = handler;     //the sigaction allows for information to be passed onto the handler
    act.sa_flags = 1;       //need to raise the flag to indicate to the struct that sigaction is being used
    sigemptyset(&act.sa_mask);  //empties and initalizes the mask

    sigaction(SIGUSR1, &act, NULL);
    int count = 0;
    while(1){
        sleep(1);
        count++;
        printf("%d\n",count);
        if(count%5 == 0){
            raise(SIGUSR1); //this command along with the kill command can be used to sed SIGUSR1
        }
        if(count == 40){
            exit(1);
        }
    }




    return 0;
 }

