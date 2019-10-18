#include <stdio.h>

int main(void) {
  float x;
  float result;

  printf("Give me x: ");
  scanf("%f", &x);
  result = (((((3*x+2)*x-5)*x-1))*x+7)*x-6; // Only 5 multiplications
  printf("The value of the polynomial at %.2f is %.2f.\n", x, result);
  return 0;
}
