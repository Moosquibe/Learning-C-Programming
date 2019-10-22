#include <stdio.h>

int main(void) {
  float x;
  float result;

  printf("Give me x: ");
  scanf("%f", &x);
  result = 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6;
  printf("The value of the polynomial at %.2f is %.2f.\n", x, result);
  return 0;
}
