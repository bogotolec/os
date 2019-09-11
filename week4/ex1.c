#include <stdio.h>
#include <stdio.h>

int main() {
	int n = 0;
	n = fork();

	if (n == 0) {
		printf("hello from child [PID - %d]\n", n);
	}
	else {
		printf("hello from parent [PID - %d]\n", n);
	}

	return 0;
}
