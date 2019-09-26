#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int sqr(int n){
	int i = 0;
	while (i != n * n) ++i;
	return i;
}

int main(){
	pid_t pid = 0;
	pid = fork();

	if (pid == 0) {
		while (1) {
			printf("I am alive!\n");
			sleep(1);
		}
	}
	else {
		sleep(10);
		kill(pid, SIGTERM);
		printf("ha-ha\n");
	}
	return 0;
}
