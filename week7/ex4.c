#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
	return a > b ? b : a;
}

void *malloc2(int size) {
	char *mem = (char *)malloc(size + sizeof(int));
	*(int*)mem = size;
	return (void*)((int*)mem + 1);
}

void *free2(void *mem) {
	free((int*)mem - 1);
}

int size_of(void *mem) {
	return ((int*)mem - 1)[0];
}

void *realloc2(void *mem, int size) {
	if (mem == NULL || size == 0)
		return NULL;

	char *mem2 = malloc2(size);
	memcpy(mem2, mem, min(size, size_of(mem)));

	return mem2;
}

int main() {

	int n = 5;
	int *arr = (int*)malloc2(n * sizeof(int));

	for (int i = 0; i < n; ++i) {
		arr[i] = i;
		printf("%d\n", arr[i]);
	}

	puts("-------------");
	realloc2(arr, 8 * sizeof(int));

	for (int i = 0; i < 8; ++i) {
		printf("%d\n", arr[i]);
	}

	puts("-------------");
	realloc2(arr, 3 * sizeof(int));

	for (int i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);
	}

	return 0;
}
