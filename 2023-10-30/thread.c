#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

/*
 * $ gcc -o thread thread.c
 * $ ./thread
 */

int x = 10;

void *mythreadfunc(void *myargp) {
	x++;
	printf("hello from thread\n");
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, mythreadfunc, NULL);
	sleep(1);
	printf("x: %d\n", x);
}
