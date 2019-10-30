#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/*
	extention of ex1.c
*/

int main() {

	int fdout;
	int fdin;

	struct stat statbuf;

	fdin = open("ex1.txt", O_RDONLY);
	fdout = open("ex1.memcpy.txt", O_RDWR | O_CREAT);

	fstat(fdin, &statbuf);

	int len = statbuf.st_size;

	ftruncate(fdout, len);

	void *src = mmap(0, len, PROT_READ, MAP_SHARED,  fdin, 0);
	void *dst = mmap(0, len, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);

	memcpy(dst, src, len);
	return 0;
}
