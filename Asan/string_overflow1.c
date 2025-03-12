#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SNT_LEN	20

int main()
{
	char sentence[] = "This is a sentence.";
	char *p = -2;

	char mem[SNT_LEN];

	strcpy(mem, sentence);

	printf("String %s is the resulting string\n", p);
	return 0;
}
