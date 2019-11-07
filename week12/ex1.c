#include <stdio.h>

int main() {
	FILE *random = fopen("/dev/random", "r");
	char string[32];
	fscanf(random, "%20s", string);
	printf("%s", string);
	return 0;
}
