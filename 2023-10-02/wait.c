#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<unistd.h>
#include<wait.h>

/*
 * $ gcc -o wait wait.c
 * $ ./wait
 */
int main(int argc, char *argv[]) {
	pid_t ret = fork();
	if (ret == 0) {
		// Child
		sleep(5);
		exit(2); // or return(2); (return from main())
	}

	// parent
	int status;
	wait(&status);
	if (WIFEXITED(status)) {
		printf("Exited normally with status: %d\n",
				WEXITSTATUS(status));
	} else {
		printf("Terminated with signal: %d\n",
				WTERMSIG(status));
	}
}
