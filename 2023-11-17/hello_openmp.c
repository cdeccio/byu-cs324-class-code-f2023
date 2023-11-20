#include<stdio.h>
#include<unistd.h>
#include<omp.h>

/*
 * $ gcc -o hello_openmp hello_openmp.c -fopenmp
 * $ ./hello_openmp
 */
int main() {
#pragma omp parallel for schedule(static,1)
	for (int i = 0; i < 12; i++) {
		int id = omp_get_thread_num();
		printf("thread %d, task %d\n", id, i);
		sleep(i);
	}
}
