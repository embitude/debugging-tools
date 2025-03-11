#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int find_min(int arr[], int start, int stop)
{
	int min = start;
	for(int i = start+1; i <= stop; i++)
		if (arr[i] < arr[min])
			min = i;
	return min;
}
void selection_sort(int arr[], int n)
{
		for (int i = 0; i < n; i++) {
				int min = find_min(arr, i, n-1);
				swap(&arr[i], &arr[min]);
		}
}

int main()
{
	int arr[100000];
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		arr[i] = rand() % 100100;
	}
	selection_sort(arr, 10000);
	return 0;
}
