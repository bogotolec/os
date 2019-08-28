#include <stdio.h>

int min(int a, int b) {
	return a < b ? a : b;
}

void print(int count, char c) {
	for (int i = 0; i < count; ++i){
		printf("%c", c);
	}
}

int main(int argc, char** argv) {
	if (argc <= 2 ) {
		puts("Enter the number as the first argument and mode as the second argument.");
		puts("\t0 - triangle to up.");
		puts("\t1 - triangle to right.");
		puts("\t2 - square.");
		puts("\t3 - star (for correct work number must be odd).");
		return 0;
	}

	int n, mode;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &mode);

	if (mode == 0) {
		for (int i = n - 1; i >= 0; --i) {
			print(i, ' ');
			print((n - i - 1) * 2 + 1, '*');
			print(i, ' ');
			puts("");
		}
	}
	if (mode == 1) {
		for (int i = 0; i < n; ++i) {
			print(min(i + 1, n - i), '*');
			puts("");
		}
	}
	if (mode == 2) {
		for (int i = 0; i < n; ++i) {
			print(n, '*');
			puts("");
		}
	}
	if (mode == 3) {
		for (int i = 0; i < n; ++i) {
			if (i == n / 2) {
				print(n, '*');
			}
			else {
				print(min(i, n - i - 1), ' ');
				print(1, '*');
				print((n / 2 - min(i, n - i - 1) - 1), ' ');
				print(1, '*');
				print((n / 2 - min(i, n - i - 1) - 1), ' ');
				print(1, '*');
			}
			puts("");
		}
	}

	return 0;
}
