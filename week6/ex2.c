#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd[2];
	pid_t pid = 0;
	pipe(fd);

	pid = fork();

	if (pid == 0) {
		char str[] = "Hello, world!\n";
		write(fd[1], str, strlen(str) + 1);
	}
	else {
		char str[16];
		read(fd[0], str, sizeof(str));
		printf("str2: %s", str);
	}

	return 0;
}
