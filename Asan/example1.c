#include <stdio.h>

#define NUMLETTERS 26

int main()
{
	char somechars[NUMLETTERS];
	for (int i = 0; i < NUMLETTERS; i++)
	{
		somechars[i] = 'a' + i;
	}
	int idx = 50;

	printf("Element: %c\n", somechars[idx]);
	return 0;
}
