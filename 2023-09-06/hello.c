#include<stdio.h>

int main(int argc, char *argv[]) {
	char buf[1024];
	fgets(buf, 512, stdin);
	printf("hello %s\n", buf);
}
