#include <pthread.h>
#include <stdio.h>

static int resource1;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

static int resource2;
static int LOOPS = 10000;

void *MyThread1(void *)
{
  for (int i = 1; i < LOOPS; ++i)
  {
    pthread_mutex_lock(&m1);
    usleep(10);
    pthread_mutex_lock(&m2);
    if (resource1 % 3)
      ++resource2;
    usleep(10);
    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m1);
  }
}

void *MyThread2(void *)
{
  for (int i = 1; i < LOOPS; ++i)
  {
    pthread_mutex_lock(&m2);
    usleep(10);
    pthread_mutex_lock(&m1);
    if (resource2 % 2 == 0)
      ++resource1;
    usleep(10);
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
  }
}

int main()
{
  pthread_t t1, t2;

	pthread_create(&t1, NULL, &MyThread1, NULL);
	pthread_create(&t2, NULL, &MyThread2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
