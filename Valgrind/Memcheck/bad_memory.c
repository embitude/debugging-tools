#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test1()
{
	const int NUM_HEIGHTS = 3;
	int *heights = malloc(NUM_HEIGHTS);
	for (int i = 0; i < NUM_HEIGHTS; i++) {
		heights[i] = i * i;
		printf("%d: %d\n", i, heights[i]);
	}
}
	

void test2()
{
	const int NUM_WEIGHTS = 5;
	long long *weights = malloc(NUM_WEIGHTS * sizeof(weights));
	for (int i = 0; i < NUM_WEIGHTS; i++)
	{
		weights[i] = 100 + i;
		printf("%d: %lld\n", i, weights[i]);
	}
	free(weights);
	weights[0] = 0;
}

void test3()
{
	const int NUM_HEIGHTS = 10;
	int *heights = malloc(NUM_HEIGHTS * sizeof(*heights));
	for (int i = 0; i < NUM_HEIGHTS; i++)
	{
		if ((heights = NULL))
		{
			heights = malloc(NUM_HEIGHTS * sizeof(*heights));
		}
	}
	free(heights);
}

char *get_string()
{
	char message[13] = "Hello World!";
	char *ret = message;
	return ret;
}

void test4()
{
	printf("String: %s\n", get_string());
}

int main()
{
    test1();
//	test2();
	//test3();
	//test4();
	return 0;
}
