#include <stdio.h>

int main(void) {
  int number, first, second, third;

  printf("Enter a three digit number: ");
  scanf("%d", &number);
  first=number/100; number = number % 100;
  second=number/10; third = number % 10;
  printf("The reverse is: %d%d%d\n", third, second, first);

  return 0;
}
