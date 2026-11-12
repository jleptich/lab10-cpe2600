/**
 * File: send_signal.c
 * Modified by: Joseph Leptich
 * 
 * Brief summary of program:
 * Is opened by the reciving file, chooses a random number and sends it to the reciving file via sigqueue
 */

 #include <stdio.h>
 #include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
 int main(int argc, char *argv[]){
    int pid;
    //checks for the pid value
    if(argc < 2){
        exit(1);
    }
    else{
        pid = atoi(argv[1]);
    }
    //seeding the random function
    srand(time(NULL));
    int count = 0;
    //every three seconds output a random value to the reciving program
    while(1){
        sleep(3);
        int i = rand();
        printf("random number from send signal: %d\n", i);
        union sigval value;
        value.sival_int = i;
        sigqueue(pid, SIGUSR1, value);
        count++;
        if(count == 5){
            kill(pid,SIGKILL);
            printf("\nKilling signal\n");
            exit(1);
        }
    }
 }
