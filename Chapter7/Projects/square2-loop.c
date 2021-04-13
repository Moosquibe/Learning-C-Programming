#include <stdio.h>

int main(void) {
  long i, start, end;

  printf("This program prints a table of squares.\n");
  printf("Enter start of entries in table: ");
  scanf("%ld", &start);
  printf("Enter end of entries in table: ");
  scanf("%ld", &end);
  getchar(); 

  for (i = start; i <= end; i++) {
    printf("%10ld%20ld\n", i, i * i);
    if ( (i + 1 - start) % 24 == 0) {
      printf("\nPress Enter to continue...\n");

      while(getchar() != '\n')
        ;
    }
  }
  return 0;
}
