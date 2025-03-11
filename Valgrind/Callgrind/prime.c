#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
  int limit = sqrt(x);
  for (int i = 2; i <= limit; ++i)
  {
    if (x % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int primeCount = 0;
  for (int i = 0; i < 1000000; ++i)
  {
    if (isPrime(i))
    {
      ++primeCount;
    }
  }
}
