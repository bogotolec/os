#include <stdio.h>

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	printf("Enter 2 numbers: ");


	int a, b;

	scanf("%d%d", &a, &b);

	swap(&a, &b);

	printf("%d %d", a, b);

	return 0;
}
