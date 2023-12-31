#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

/*
 * $ gcc -o thread thread.c
 * $ ./thread
 */

void *mythreadfunc(void *myargp) {
	printf("hello from thread\n");
	exit(0);
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, mythreadfunc, NULL);
	sleep(3);
	printf("main thread terminating\n");
}
