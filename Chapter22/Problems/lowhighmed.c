#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10000

int compare_int(const void *a, const void* b) {
  int num1 = *(int*)a;
  int num2 = *(int*)b;

  if (num1 == num2)
    return 0;
  else if (num1 >= num2)
    return 1;
  else
    return -1;
}

int main(int argc, char *argv[]) {
  FILE *fp;
  int ints[MAX_NUMBER], i = 0;
  char c;

  if (argc != 2) {
    fprintf(stderr, "Usage: lowhighmed <input-file>\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  while((fscanf(fp, " %d", &ints[i])) == 1)
    i++;

  fclose(fp);

  qsort(ints, i, sizeof(int), compare_int);

  printf("Smallest number: %d\n", ints[0]);
  printf("Largest number: %d\n", ints[i-1]);
  printf("Median: %d\n", i % 2 == 0 ? (ints[i/2 - 1] + ints[i/2])/2 : ints[(i-1)/2]);
  
  return 0;
}