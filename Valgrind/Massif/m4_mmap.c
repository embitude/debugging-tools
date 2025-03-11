#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

const size_t DATA_SIZE = 100U;
const size_t BLOCK_SIZE = 1000000;

int main()
{
  //long **data = new long *[DATA_SIZE];
	long **data = (long **)malloc(DATA_SIZE * sizeof(*data));

  for (size_t i = 0; i < DATA_SIZE; ++i)
  {
    data[i] = (long *)(mmap(NULL,
       BLOCK_SIZE*sizeof(long),
       PROT_READ | PROT_WRITE,
       MAP_SHARED | MAP_ANONYMOUS, -1, 0));
    // do something with data[i]
    usleep(100000);
  }

  sleep(1);

  for (size_t i = 0; i < DATA_SIZE; ++i)
  {
    munmap(data[i], BLOCK_SIZE*sizeof(long));
  }

  free(data);
}
