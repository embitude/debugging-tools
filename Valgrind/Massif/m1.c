#include <unistd.h>

const size_t DATA_SIZE = 100U;
const size_t BLOCK_SIZE = 10000;

int main()
{
  //long **data = new long *[DATA_SIZE];
	long **data = (long **)malloc(DATA_SIZE * sizeof(long *));

  for (size_t i = 0; i < DATA_SIZE; ++i)
  {
    //data[i] = new long[BLOCK_SIZE];
	data[i] = (long *)malloc(DATA_SIZE * sizeof(long));
    // do something with data[i]
    usleep(100000);
  }
  sleep(1);

  for (size_t i = 0; i < DATA_SIZE; ++i)
  {
    //delete [] data[i];
	free(data[i]);
  }
  //delete [] data;
	free(data);
}
