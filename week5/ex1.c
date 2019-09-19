#include <stdio.h>
#include <pthread.h>

void* foo() {
	printf("Thread number: %d.\n", pthread_self());

	pthread_exit(0);
}

int main() {

	int n = 10;
	pthread_t tid;

	for (int i = 0; i < n; ++i) {

		pthread_create(&tid, NULL, foo, NULL);
		printf("Thread <%d> created.\n", tid);

		pthread_join(tid, NULL);

	}

	return 0;
}
