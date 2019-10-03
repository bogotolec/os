#include <stdio.h>
#include <stdlib.h> // for malloc

int main() {

	char **s = malloc(1 * sizeof(char)); // Memory allocation
	char foo[] = "Hello World!";

	*s = foo;
	printf("s is %p\n", s); // s is the pointer

	s[0] = foo;
	printf("s[0] is %s", s[0]);

	return 0;
}
