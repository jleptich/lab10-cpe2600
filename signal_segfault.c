/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Joseph Leptich
 * 
 * Brief summary of modifications: 
 * Messed around with sigsegv to see what happens when the handler does not address a fault
 */


#include <stdio.h>
#include <signal.h>

//creates a infinite loop of calling the handler as the segmentation fault is never dealt with
void handler(int var){
    printf("Segmentation fault DETECTED\n\n");
    return;
}
int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, &handler);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}