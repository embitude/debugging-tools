#include <stdlib.h>
#include <stdio.h>

struct numbers
{
  int n;
  int *nums;
};

int n;
struct numbers *numbers;

void
create_numbers (struct numbers **nrs, int *n)
{
  *n = 3;
  *nrs = malloc ((sizeof (struct numbers) * 3));
  struct numbers *nm = *nrs;
  for (int i = 0; i < 3; i++)
    {
      nm->n = i + 1;
      nm->nums = malloc (sizeof (int) * (i + 1));
      for (int j = 0; j < i + 1; j++)
        nm->nums[j] = i + j;
      nm++;
    }
}

void
output_report ()
{ 
  puts ("numbers"); 
  for (int i = 0; i < numbers->n; i++)
    printf ("Number: %d\n", numbers->nums[i]);
  printf ("\n");
}

int
main ()
{ 
  create_numbers (&numbers, &n);
  for (int i = 0; i < 2; i++)
    {
      output_report ();
      numbers++;
    }
  return 0;
}

