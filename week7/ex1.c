#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *usage = "Usage: %s [program name]\n";
char *not_exist = "File does not exist";

int main(int argc, char **argv) {
	if (argc != 2){
		printf(usage, argv[0]);
		return 0;
	}

	if (access(argv[1], R_OK) != -1){
		char command[256];
		strcpy(command, "size ");
		strcat(command, argv[1]);
		system(command);
	}
	else {
		puts(not_exist);
	}

	return 0;
}
