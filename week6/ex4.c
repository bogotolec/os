#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigkill_handler(){
	printf("Someone killed me!\n");
	exit(0);
}

void sigstop_handler(){
	printf("Someone stopped me!\n");
	exit(0);
}

void sigusr1_handler(){
	printf("Someone usr1ed me!\n");
	exit(0);
}

int sqr(int n){
	int i = 0;
	while (i != n * n) ++i;
	return i;
}

int main(){
	signal(SIGKILL, sigkill_handler);
	signal(SIGSTOP, sigstop_handler);
	signal(SIGUSR1, sigusr1_handler);

	for (int i = 1000; i < 10000; i += 2) {
		int x = sqr(i);
	}
	return 0;
}
