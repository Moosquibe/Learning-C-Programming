#include <stdio.h>

int gcd(int n, int m) {
  int rem;

  while ((rem = n % m) != 0) {
    n = m;
    m = rem;
  }
  return m;
}

int main() {
  int numerator, denominator, divisor;

  printf("Enter a fraction: ");
  scanf("%d /%d", &numerator, &denominator);

  while ((divisor = gcd(numerator, denominator)) != 1) {
    numerator /= divisor;
    denominator /= divisor;
  }

  printf("In lowest terms: %d/%d\n", numerator, denominator);
  return 0;
}
