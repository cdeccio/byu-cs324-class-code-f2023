#include<stdio.h>

/*
 * $ cat test.txt
 * $ cat
 * $ cat < test.txt
 *
 * $ gcc -o hello hello.c
 * $ ./hello | grep OUT
 * $ ./hello | grep ERR
 * $ ./hello | grep FOO
 */
int main(int argc, char *argv[]) {
	fprintf(stdout, "hello STDOUT\n");
	fprintf(stderr, "hello STDERR\n");
}
