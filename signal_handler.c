/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Joseph Leptich
 * 
 * Brief summary of modifications:
 * updated the handler parameters to fit with the signal function call, 
 * experimented with the different ways to send SIGINT via any ctrl+ command and with the kill function
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */

 //updated the handler so it can actually have the parameters needed to be used inside signal
void handle_signal(int var) {
    printf("Received a signal\n");
    return;
}

int main() {

    // Register for the signal
    void (*sig_handle)(int);
    sig_handle = handle_signal;
    signal(SIGINT, &handle_signal);
    int pid = getpid();
    int count = 0;
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
        //sends a sigint and the program keeps running
        if(count == 2){
            kill(pid, SIGINT);
        }
        //kills the signal and closes the program
        if(count == 10){
            kill(pid, SIGKILL);
        }
        count++;
    }

    return 0;
}