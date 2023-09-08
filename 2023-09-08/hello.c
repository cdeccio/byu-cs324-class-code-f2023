#include<stdio.h>

/*
 * $ gcc -o hello hello.c
 * $ ./hello > myfile.txt
 * $ cat myfile.txt
 * $ ./hello 1> myfile.txt
 * $ cat myfile.txt
 * $ ./hello 2> myfile.txt
 * $ cat myfile.txt
 * $ ./hello > myfile.txt 2>&1
 * $ cat myfile.txt
 * $ ./hello 2>&1 > myfile.txt
 * $ cat myfile.txt
 */
int main(int argc, char *argv[]) {
	fprintf(stdout, "hello STDOUT\n");
	fprintf(stderr, "hello STDERR\n");
}
