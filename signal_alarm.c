/**
 * File: signal_alarm.c
 * Modified by: Joseph Leptich
 * 
 * Brief summary of program: 
 * sets the alarm function for five seconds, when the alarm goes off the handler prints it out
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//i keeps track of the amount of alarms that went off
volatile int i;
void handler(int nothing){
    printf("The alarm went off!\n");
    alarm(5);
    i++;
    return;
}

int main(void){

    signal(SIGALRM, &handler);
    int count = 0;
    i = 0;
    alarm(5);
    //while loop that ends when count equals 20
    while(1){
        printf("%d alarms went off\n\n", i);
        sleep(1);
        count++;

        if(count == 20){
            kill(getpid(), SIGKILL);
        }
    }



    return 0;
}