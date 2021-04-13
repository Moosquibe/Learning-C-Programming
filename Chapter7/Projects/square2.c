#include <stdio.h>

int main(void) {
  long i, start, end;

  printf("This program prints a table of squares.\n");
  printf("Enter start of entries in table: ");
  scanf("%ld", &start);
  printf("Enter end of entries in table: ");
  scanf("%ld", &end);

  for (i = start; i <= end; i++)
    printf("%10ld%20ld\n", i, i * i);

  return 0;
}
