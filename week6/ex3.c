#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void f(){
	printf("Interrupted by user.\n");
	exit(0);
}

int unoptimized_sqr(int n){
	int i = 0;
	while (i != n * n) ++i;
	return i;
}

int main() {
	signal(SIGINT, f);

	for (int i = 1000; i < 10000; ++i) {
		printf("Square of %d is %d!\n", i, unoptimized_sqr(i));
	}

	return 0;
}
