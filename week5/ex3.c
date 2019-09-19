#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MUCH 1

int stack[1024 * 1024];
int ptr = -1;

int cons_sleep = 1;
int prod_sleep = 0;

void *consumer() {

	for (int i = 0; i < 100000000; ++i) {
		while (cons_sleep);

		--ptr;

		if (ptr > 100000) prod_sleep = 1;
		if (ptr < 100) prod_sleep = 0, cons_sleep = 1;
	}
}

void *producer() {
	int c = 1;

	while (c < 100000000) {
		while (prod_sleep);

		stack[++ptr] = c++;

		if (ptr < 100) cons_sleep = 1;
		if (ptr > 100000) cons_sleep = 0, prod_sleep = 1;
	}
}

int main() {
	pthread_t pid_c, pid_p;

	pthread_create(&pid_p, NULL, producer, NULL);
	pthread_create(&pid_c, NULL, consumer, NULL);

	for (int i = 0; i < 50; ++i){
		printf("stack[%d] = %d\n", ptr, stack[ptr]); // incorrect message, first and second ptr almost always are different

		sleep(MUCH);
	}

	return 0;
}
