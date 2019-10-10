#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB10 (1024 * 1024 * 10)

int main() {
	for (int i = 0; i < 10; ++i) {
		char* ptr = malloc(sizeof(char) * MB10);
		memset(ptr, 0, MB10);
		sleep(1);
	}
	return 0;
}
