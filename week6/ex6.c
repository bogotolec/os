#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <string.h>

#define COUPLE_OF_SECONDS 2

int main() {
	pid_t pid1 = 0;

	int fd[2];
	pipe(fd);

	pid1 = fork();

	if (pid1 == 0) {
		char a[16] = "";

		read(fd[0], a, sizeof(a));

		pid_t pid2 = atoi(a);
		printf("child1: pid got\n");
		sleep(COUPLE_OF_SECONDS);
		kill(pid2, SIGSTOP);
	}
	else {
		pid_t pid = 0;
		pid = fork();

		if (pid == 0) {
			while (1) {
				printf("child2: I am alive!\n");
				fflush(stdout);
				sleep(1);
			}
		}
		else {
			char tmp[16];
			sprintf(tmp, "%d", pid);

			write(fd[1], tmp, strlen(tmp) + 1);

			int status;
			waitpid(pid, &status, WUNTRACED);
			printf("parent: I detected that somebody stopped the second child\n");
			fflush(stdout);

		}
	}

	return 0;
}
