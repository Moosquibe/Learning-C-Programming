#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int int_comp(const void *i, const void *j) {
    int k = *(int*) i, l =  *(int*) j;
    return i - j;
}

int main(int argc, char* argv[]) {
  int a[N];
  clock_t start_clock;

  for(int i = 0; i < N; i++)
      a[i] = N - i; 

  start_clock = clock();

  qsort(a, N, sizeof(int), int_comp);

  printf("This took %g sec.\n", (clock() - start_clock) / (double) CLOCKS_PER_SEC);
  exit(EXIT_SUCCESS);
}