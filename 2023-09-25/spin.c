#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void somefunc(int signum) {
	printf("just kidding\n");
}

/*
 * $ gcc -o spin spin.c
 * $ ./spin
 * Enter Ctrl-C while program is running
 */
int main(int argc, char *argv[]) {
	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = somefunc;
	sigact.sa_flags = 0;

	// install signal handler for SIGINT
	sigaction(SIGINT, &sigact, NULL);
	
	for (int i = 0; i < 1000; i++) {
		printf("main loop %d\n", i);
		sleep(1);
	}
}
