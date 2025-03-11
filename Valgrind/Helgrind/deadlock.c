#include <stdio.h>
#include <pthread.h>

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg)
{
	int *value = (int *)arg;
	if (*value == 1)
	{
		pthread_mutex_lock(&m1);
		pthread_mutex_lock(&m2);
	}
	else
	{
		pthread_mutex_lock(&m2);
		pthread_mutex_lock(&m1);
	}
	pthread_mutex_unlock(&m1);
	pthread_mutex_unlock(&m2);
	return NULL;
}

int main()
{
	pthread_t p1, p2;
	int arg1 = 1, arg2 = 2;
	
	pthread_create(&p1, NULL, worker, &arg1);
	pthread_create(&p2, NULL, worker, &arg2);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	return 0;	
}		
