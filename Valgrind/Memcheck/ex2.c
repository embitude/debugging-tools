#include <stdio.h>

void bar() 
{
	int *p = NULL;
	p = (int *)malloc(sizeof(int));
	*p = 42;
}

void foo()
{
	bar();
}

int main()
{
	foo();
}
