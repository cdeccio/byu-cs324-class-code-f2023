#include<fcntl.h>
#include<stdio.h>

/*
 * $ gcc -o badopen badopen.c
 * $ ./badopen does-not-exist.txt
 * $ ./badopen /etc/shadow
 */
int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY);
	printf("fd: %d\n", fd);
}