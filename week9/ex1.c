#include <stdio.h>
#include <stdlib.h>
//#include <>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: %s <n>\n", argv[0]);
		return 0;
	}

	int n = atoi(argv[1]);
	int hits = 0, misses = 0;

	int *page_frames = calloc(n, sizeof(int));
	unsigned char *counters = calloc(n, sizeof(unsigned char));

	FILE *f;
	if ( (f = fopen("input.txt", "r")) == NULL) {
		printf("file <input.txt> doesn't exist\n");
		return 0;
	}

	int page = 0;
	while (fscanf(f, "%d", &page) == 1) {
		int hitted = 0;
		for (int i = 0; i < n; ++i) {
			counters[i] >>= 1;
			if (!hitted && page_frames[i] == page) {
				hitted = 1;
				hits += 1;
				counters[i] |= 0x80;
			}
		}

		if (!hitted) {
			misses += 1;
			int mini = 0;
			int zero = 0;
			int min = counters[0];
			for (int i = 1; i < n; ++i) {
				if (counters[i] < min) {
					min = counters[i];
					mini = i;
				}
				if (!zero && page_frames[i] == 0){
					zero = 1;
					mini = i;
					min = 0;
				}
			}
			page_frames[mini] = page;
			counters[mini] = 0x80;
		}

	}

	printf("%d/%d\n", hits, misses);

	fclose(f);
}
