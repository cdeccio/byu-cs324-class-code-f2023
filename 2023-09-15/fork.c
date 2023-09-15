#include <unistd.h>
#include <stdio.h>

/*
 * $ gcc -o fork fork.c
 * $ ./fork
 */
int main() {
	int ret;
	ret = fork();
	if (ret == 0) {
		printf("I am the child!! ret=%d pid=%d ppid=%d\n",
				ret, getpid(), getppid());
	} else {
		printf("I am the parent!! ret=%d pid=%d ppid=%d\n",
				ret, getpid(), getppid());
	}
	sleep(1);
}
