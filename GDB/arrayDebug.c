/**
 * A simple buggy program to demonstrate the 
 * usage of GDB.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Creates a random array of size n filled with
 * integers in the range [0, 9]
 */
int *randomArray(int n);

/**
 * Computes the average of the elements in the
 * given array.
 */
double average(const int *a, int n);

/**
 * prints the given array to the standard output
 */
void printArray(const int *a, int n);

//default value
const int N = 10;

int main(int argc, char **argv) {

  int n = N;
  if(argc != 2) {
    printf("Usage: %s n\n", argv[0]);
    exit(1);
  }
  srandom(time(NULL));

  n = atoi(argv[1]);
  int *arr = randomArray(n);
  printf("Computing average of ");
  printArray(arr, n);
  double ave = average(arr, n);
  printf("\nAverage = %f\n", ave);

  return 0;
}

int *randomArray(int n) {
  int *a = malloc(n * sizeof(int));
  int i;
  for(i=0; i<n; i++) {
    a[i] = random() % 10;
  }
  return;
}

double average(const int *a, int n) {
  int i, sum;
  for(i=0; i<N; i++) {
    sum += a[i];
  }
  return (double) sum / n;
}

void printArray(const int *a, int n) {
  int i;
  printf("[ ");
  for(i=0; i<n; i++) {
    printf("%d ", a[i]);
  }
  printf("]");
  return;
}
