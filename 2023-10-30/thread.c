#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

/*
 * $ gcc -o thread thread.c
 * $ ./thread
 */

void *mythreadfunc(void *myargp) {
	sleep(3);
	printf("hello from thread\n");
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, mythreadfunc, NULL);
	printf("main thread terminating\n");
}
