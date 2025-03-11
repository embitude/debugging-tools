#include <stdio.h>

typedef struct data {
	char a;
	int b;
	double f;
}data_t;

void bar() 
{
	int *p = NULL;
	p = (int *)malloc(4 * sizeof(int));
	*p = 42;
	free(p);
}

void foo()
{
	data_t *allocation = malloc(sizeof(data_t));
	bar();
}

int main()
{
	foo();
}
