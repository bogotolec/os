#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Please, enter the number of elements in array: ");
	scanf("%d", &n);

	int *arr = calloc(n, sizeof(int));

	for (int i = 1; i < n; ++i) {
		arr[i] = i;
	}

	for (int i = 0; i < n; ++i) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);

	return 0;
}
