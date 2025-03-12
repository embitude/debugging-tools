#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SNT_LEN	19

int main()
{
	char sentence[] = "This is a sentence.";

	char *mem = malloc(SNT_LEN);

	strcpy(mem, sentence);

	printf("String is %s\n", mem);
	return 0;
}
