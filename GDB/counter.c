#include <stdio.h>
#include <pthread.h>

#define BIG 100000000UL
unsigned long counter = 0;


void *thread_fn(void *arg)
{
	unsigned int i;
	for (i = 0; i < BIG; i++) {
		counter++;
	}
	return NULL;
}

int main()
{
	pthread_t id1, id2;
	pthread_create(&id1, NULL, thread_fn, NULL);
	pthread_create(&id2, NULL, thread_fn, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	return 0;
}
	
