#include <stdio.h>

int main() {
  int area, num1, num2;
  printf("Enter phone number [(xxx) xxx-xxxx]:  ");
  scanf("(%d) %d-%d", &area, &num1, &num2);
  printf("You entered %d.%d.%d\n", area, num1, num2);
  return 0;
}
