#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd[2];
	pipe(fd);

	char str1[] = "Hello, world!\n";
	char str2[16];

	write(fd[1], str1, strlen(str1) + 1);
	read(fd[0], str2, sizeof(str2));

	printf("str2: %s", str2);
	return 0;
}
