#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

/*
 * $ gcc -o signals signals.c
 * $ ./signals
 */
int main(int argc, char *argv[]) {
	sigset_t mask, oldmask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigprocmask(SIG_SETMASK, &mask, &oldmask);

	for (int i = 0; i < 1000; i++) {
		if (i == 10) {
			sigprocmask(SIG_SETMASK, &oldmask,
					NULL);
		}
		printf("main loop %d\n", i);
		sleep(1);
	}
}
