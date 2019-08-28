#include <stdio.h>

int main() {
	puts("Enter the string: ");

	char s[256];
	scanf("%s", s);

	char *p = s;
	while (*(++p) != 0);

	do {
		putchar(*(--p));
	} while (p != s);

	return 0;
}
