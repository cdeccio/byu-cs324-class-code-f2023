#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

/*
 * $ gcc -o signals signals.c
 * $ ./signals
 * Enter Ctrl-C while program is running
 */
int main(int argc, char *argv[]) {
	pid_t ret = fork();
	if (ret == 0) {
		for (int i = 0; i < 1000; i++) {
			printf("main loop %d\n", i);
			sleep(1);
		}
	}
	sleep(3);
	kill(ret, SIGINT); // or kill(ret, 2);
}
