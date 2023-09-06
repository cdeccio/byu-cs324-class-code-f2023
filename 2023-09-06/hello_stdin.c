#include<stdio.h>

/*
 * $ gcc -o hello_stdin hello_stdin.c
 * $ ./hello_stdin
 * world
 */
int main(int argc, char *argv[]) {
	char buf[1024];
	fgets(buf, 512, stdin);
	printf("hello %s\n", buf);
}
