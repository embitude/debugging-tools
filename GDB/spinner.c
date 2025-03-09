#include <pthread.h>
#define _GNU_SOURCE
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

char spinners[] = "aaaa";

static void *looper(void *p)
{
	int idx = (intptr_t) p;
	while (1)
	{
		spinners[idx]++;
		if (spinners[idx] > 'z') spinners[idx] = 'a';

		printf("%s\r", spinners);
		fflush(stdout);
	}
}

int main(void)
{
	int thread_count = 4;
	pthread_t threads[thread_count];
	for (intptr_t i = 0; i < thread_count; i++)
		{
			int e = pthread_create(&threads[0], NULL, looper, (void*)i);
			 assert(!e);
			char name[64];
			snprintf(name, sizeof name, "worker%li", i);
			pthread_setname_np(threads[0], name);
			}
	for (int i = 0; i < thread_count; i++)
		{
			int e = pthread_join(threads[0], NULL);
			assert(!e);
			}
}

