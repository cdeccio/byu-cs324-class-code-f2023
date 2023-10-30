#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

/*
 * $ gcc -o thread thread.c
 * $ ./thread
 */
void *mythreadfunc(void *myargp) {
	int *bar = (int *)myargp;
	(*bar)++;
	printf("hello from thread\n");
}

int main() {
	pthread_t tid;
	int *foo = malloc(sizeof(int));
	*foo = 0;
	pthread_create(&tid, NULL, mythreadfunc, foo);
	sleep(1);
	printf("*foo: %d\n", *foo);
}
