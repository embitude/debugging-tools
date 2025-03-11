#include <pthread.h>
#include <stdio.h>

void* worker_thread(void* in);
int backdoor();

static int forget_me_not;

void other_work(int n, int i)
{
  if (i % n == 0)
  {
    ++forget_me_not;
  }
  else
  {
    usleep(1);
  }
}

int backdoor()
{
  return forget_me_not;
}

void other_work(int n, int i);

void* worker_thread(void* in)
{
  int number = (long)in;
  for (int i = 0; i < 1000000; ++i)
  {
    other_work(number, i);
  }
  return 0;
}

int main()
{
  pthread_t t1, t2;
  pthread_create(&t1, 0, worker_thread,
     (void*)7);
  pthread_create(&t2, 0, worker_thread,
    (void*)13);

  pthread_join(t1, 0);
  pthread_join(t2, 0);

	printf("Forgotten statis is %u, ought to be %u\n", backdoor(),1000000/7 + 1000000/13 + 2);
}
