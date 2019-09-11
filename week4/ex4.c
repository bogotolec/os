#include <stdlib.h>
#include <stdio.h>

int main() {
	int n = 0;
	while (1) {
		n = fork();

		char str[256];
		fgets(str, 256, stdin);
		if (!n) {
			system(str);
			return 0;
		}
	}
	return 0;
}
