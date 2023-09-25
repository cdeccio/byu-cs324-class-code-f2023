#include<stdio.h>
#include<unistd.h>

/*
 * $ gcc -o spin spin.c
 * $ ./spin
 * Enter Ctrl-C while program is running
 */
int main(int argc, char *argv[]) {
	for (int i = 0; i < 1000; i++) {
		printf("main loop %d\n", i);
		sleep(1);
	}
}
