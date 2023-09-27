#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void somefunc(int signum) {
	for (int i = 0; i < 10; i++) {
		printf("handler loop %d (signum=%d)\n", i, signum);
		sleep(1);
	}
}

/*
 * $ gcc -o signals signals.c
 * $ ./signals
 * Enter Ctrl-C while program is running
 */
int main(int argc, char *argv[]) {
	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = somefunc;
	sigact.sa_flags = 0;

	// install signal handler for SIGCHLD
	sigaction(SIGINT, &sigact, NULL);
	
	for (int i = 0; i < 1000; i++) {
		printf("main loop %d\n", i);
		sleep(1);
	}
}
