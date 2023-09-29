#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

int globx = 12;

void somefunc(int signum) {
	globx++;
}

/*
 * $ gcc -o signals signals.c
 * $ ./signals
 * Enter Ctrl-C after program is running
 */
int main(int argc, char *argv[]) {

	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = somefunc;
	sigact.sa_flags = 0;

	// install signal handler for SIGINT
	sigaction(SIGINT, &sigact, NULL);
	
	for (int i = 0; i < 1000; i++) {
		printf("main loop %d globx=%d\n", i, globx);
		sleep(1);
	}
}
