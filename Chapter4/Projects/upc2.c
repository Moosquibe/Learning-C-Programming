#include <stdio.h>

int main(void) {
  int upc, d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5;
  int first_sum, second_sum, total;

  printf("Enter the first 11 digits of a UPC: ");
  scanf("%d", &upc);
  d = upc/10000000000;
  i1 = upc/1000000000 % 10;
  i2 = upc/100000000 % 10;
  i3 = upc/10000000 % 10;
  i4 = upc/1000000 % 10;
  i5 = upc/100000 % 10;
  j1 = upc/10000 % 10;
  j2 = upc/1000 % 10;
  j3 = upc/100 % 10;
  j4 = upc/10 % 10;
  j5 = upc % 10;

  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;

  printf("Check digit: %d\n", 9 - ((total -1) % 10));

  return 0;
}

