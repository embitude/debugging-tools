#include <stdio.h>
#include <stdlib.h>


long int bizarre(long int n)
{
  if (n == 1)
  {
    return n;
  }
  else if (0L == n%2L)
  {
    return bizarre(n/2L);
  }
  else
  {
    return bizarre((3L*n + 1L)/2L);
  }
}

int main()
{
  for (long int i = 1L; i < 200000000L; ++i)
  {
    bizarre(i);
  }
}
