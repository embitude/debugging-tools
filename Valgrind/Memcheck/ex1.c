#include <stdio.h>

void bar() 
{
	int *p = NULL;
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
