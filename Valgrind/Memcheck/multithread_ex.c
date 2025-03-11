#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LOOP_COUNT 100000

static volatile long count = 0;

void *ThreadAdd(void *a) {
	long i;
	long *tmp;
	for (i = 0; i < LOOP_COUNT; i++) {
		tmp = malloc(sizeof(long));
		*tmp = count;
		*tmp = *tmp + 1;
		count = *tmp;
		 
		*tmp = count;
		*tmp = *tmp + 1;
		count = *tmp;
	}
	return NULL;
}

int main() {
	pthread_t tid1, tid2;
	
	if (pthread_create(&tid1, NULL, ThreadAdd, NULL) != 0) {
		printf("Unable to create thread-1\n");
		return -1;
	}
	if (pthread_create(&tid2, NULL, ThreadAdd, NULL) != 0) {
		printf("Unable to create thread-2\n");
		return -1;
	}
	if (pthread_join(tid1, NULL) != 0) {
		printf("Unable to join thread1\n");
		return -1;
	}
	if (pthread_join(tid2, NULL) != 0) {
		printf("Unable to join thread2\n");
		return -1;
	}
	long expected_count = LOOP_COUNT * 4;
	if (count != expected_count) 
		printf("Count is %ld, should be %ld\n", count, expected_count);
	else
		printf("OK. Count is %ld, should be %ld\n", count, expected_count);
	return 0;
}
