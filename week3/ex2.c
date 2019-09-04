#include <stdio.h>

void bubble_sort(int *arr, int n) {
	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1]) {
				arr[j + 1] += arr[j];
				arr[j] = arr[j + 1] - arr[j];
				arr[j + 1] -= arr[j];
			}
		}
	}
}

int main(){
	int arr[10] = {5, 7, 6, 3, 4, 8, 9, 2, 0 ,1};
	int n = 10;

	bubble_sort(arr, n);

	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}

	return 0;
}
