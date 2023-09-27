#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void somefunc(int signum) {
	printf("child terminated\n");
}

/*
 * $ gcc -o signals signals.c
 * $ ./signals
 * Enter Ctrl-C while program is running
 */
int main(int argc, char *argv[]) {
	pid_t ret = fork();
	
	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = somefunc;
	sigact.sa_flags = 0;

	// install signal handler for SIGCHLD
	sigaction(SIGCHLD, &sigact, NULL);
	
	if (ret == 0) {
		sleep(3);
	} else {
		for (int i = 0; i < 1000; i++) {
			printf("main loop %d\n", i);
			sleep(1);
		}
	}
}
