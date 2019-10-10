#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#define MB10 (1024 * 1024 * 10)

int main() {
	struct rusage usage;

	for (int i = 0; i < 10; ++i) {
		char* ptr = malloc(sizeof(char) * MB10);
		memset(ptr, 0, MB10);
		getrusage(RUSAGE_SELF, &usage);
		printf("Usage: %li\n", usage.ru_maxrss);
		sleep(1);
	}
}
