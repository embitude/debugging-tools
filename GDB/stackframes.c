#include <stdio.h>

int f4()
{
	int a4 = 40;
	int b4 = 400;
	return 4;
}

int f3(int a, int b)
{
	int a3 = 30;
	int b3 = 300;
	f4();
	return 3;
}

int f2(int i)
{
	int a2 = 20;
	int b2 = 200;
	f3(a2, b2);
	return 2;
}
int f1(char *s) 
{
	int a1 = 10;
	int b1 = 100;
	f2(a1);
	return 1;
}

int main()
{
	char buf[10] = "HELLO";
	f1(buf);
	printf("That's was v cool\n");
	int m1 = 54;
	return m1;
}
