#include <stdio.h>

float power(float x, int n) {
  float result = 1;
  for(int i = 0; i < n; i++) {
    result *= x;
  }
  return result;
}

float polynomial(float x) {
  return 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;
}

int main(void) {
  float x;
  printf("Enter a value: ");
  scanf("%f", &x);

  printf("Value of the polynomial: %.4f\n", polynomial(x));
  return 0;
}
