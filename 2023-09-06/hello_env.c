#include<stdio.h>
#include<stdlib.h>

/*
 * $ gcc -o hello_env hello_env.c
 * $ ./hello_env
 * $ FOO=world ./hello_env
 */
int main(int argc, char *argv[]) {
	char *envval;
	envval = getenv("FOO");
	if (envval == NULL) {
		printf("hello (empty)");
	} else {
		printf("hello %s\n", envval);
	}
}
