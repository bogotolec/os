#include <stdio.h>

void qsort(int *arr, int l, int r) {
	printf("%d %d\n", l, r);
	int x = arr[(l + r) >> 1];
	int i = l, j = r;

	while (i <= j) {
		while (arr[i] < x) ++i;
		while (arr[j] > x) --j;

		if (i <= j) {
			int c = arr[j];
			arr[j] = arr[i];
			arr[i] = c;

			++i, --j;
		}
	}

	if (j > l) qsort(arr, l, j);
	if (r > i) qsort(arr, i, r);
}

int main() {

	int a[10] = {5, 7, 6, 3, 4, 8, 9, 2, 0, 1};
	int n = 10;
	qsort(a, 0, n - 1);

	for (int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	return 0;
}
