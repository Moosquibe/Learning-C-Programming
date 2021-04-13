#include <stdio.h>

int main(void) {
  int number, digits;
  printf("Enter a number: ");
  scanf("%d", &number);
  if (number <= 9)
    digits = 1;
  else if (number <= 99)
    digits = 2;
  else if (number <= 999)
    digits = 3;
  else
    digits = 4;

  printf("The number 374 has %d digits\n", digits);
  return 0;
}
