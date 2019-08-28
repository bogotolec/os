#include <stdio.h>

void print(int count, char c) {
	for (int i = 0; i < count; ++i){
		printf("%c", c);
	}
}

int main(int argc, char** argv) {
	if (argc <= 1 ) {
		puts("Enter the number as the argument.");
		return 0;
	}

	int n;
	sscanf(argv[1], "%d", &n);

	for (int i = n - 1; i >= 0; --i) {
		print(i, ' ');
		print((n - i - 1) * 2 + 1, '*');
		print(i, ' ');
		puts("");
	}

	return 0;
}
