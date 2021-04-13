#include <stdio.h>

float power(float x, int n) {
  float result;

  if (n == 0) {
    result = 1;
  } else if (n % 2 == 0) {
    result = power(x, n/2);
    result = result * result;
  } else {
    result = x * power(x, n-1);
  }

  return result;
}

int main(void) {
  float x;
  int n;

  printf("Enter a value for x: ");
  scanf("%f", &x);

  printf("Enter a value for n: ");
  scanf("%d", &n);

  printf("The value of x^n is: %f\n", power(x, n));
}
