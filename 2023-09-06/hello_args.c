#include<stdio.h>

/*
 * $ gcc -o hello_args hello_args.c
 * $ ./hello_args world
 */
int main(int argc, char *argv[]) {
	printf("hello %s\n", argv[1]);
}
