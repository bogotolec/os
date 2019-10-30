#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {

	int fdout;

	char* str = "Have a nice day";
	int len = 15;

	fdout = open("ex1.txt", O_RDWR);
	ftruncate(fdout, len);

	void *dest = mmap(0, len, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);

	memcpy(dest, str, len);
	return 0;
}
