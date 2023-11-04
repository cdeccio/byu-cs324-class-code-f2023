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
	sleep(3);
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, mythreadfunc, NULL);
	pthread_join(tid, NULL);
	printf("main thread terminating\n");
}
