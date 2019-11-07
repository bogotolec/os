#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	if (argc < 2) return 0;

	int i = 1;
	int a = 0;

	if (!strcmp(argv[1], "-a") ){
		i += 1;
		a = 1;
	}

	char buff[1024];      // 1 kb
	char str[1024 * 64]; // 64kb


	while (fgets(buff, 1024, stdin)) {
		strcat(str, buff);
	}

	printf("%s\n", str);

	while (i < argc) {
		FILE * f;
		if (a) f = fopen(argv[i], "a");
		else f = fopen(argv[i], "w");

		fprintf(f, "%s", str);

		++i;
	}
	return 0;
}

