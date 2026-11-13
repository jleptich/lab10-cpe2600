## README


## Part 2:
The signal_handler.c program registers a handler for SIGINT. The handler was changed so it no longer exits the program. Pressing Ctrl+C or using the kill command to send SIGINT triggers the handler while the program keeps running, so the program has to be stopped with SIGKILL.

## Part 3:
The signal_alarm.c program schedules an alarm using the alarm function. After 5 seconds the operating system sends SIGALRM, and the handler prints that the signal was received.

The signal_segfault.c program dereferences a NULL pointer, which causes the operating system to send SIGSEGV. The installed handler prints a message and returns. Because execution resumes at the instruction that caused the fault, the fault happens again and the handler runs repeatedly.

## Part 3: 
The signal_sigaction.c program uses sigaction with the SA_SIGINFO flag to register a handler for SIGUSR1. The program waits in an infinite loop, and when the signal arrives the handler prints the process ID of the sender.

## Part 4: 
The recv_signal.c program registers a SIGUSR1 handler using sigaction, waits in a loop, and prints the integer value it receives with the signal.

The send_signal.c program takes the receiver's process ID as a command line argument, generates a random integer seeded with the current time, prints it, and sends it to the receiver along with SIGUSR1 using sigqueue.