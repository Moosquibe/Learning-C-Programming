#include <stdio.h>

int gcd(int n, int m) {
  int rem;

  while ((rem = n % m) != 0) {
    n = m;
    m = rem;
  }
  return m;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator) {
  int divisor;
  *reduced_numerator = numerator;
  *reduced_denominator = denominator;
  while ((divisor = gcd(*reduced_numerator, *reduced_denominator)) != 1) {
    *reduced_numerator /= divisor;
    *reduced_denominator /= divisor;
  }
}


int main() {
  int numerator, denominator;

  printf("Enter a fraction: ");
  scanf("%d /%d", &numerator, &denominator);

  reduce(numerator, denominator, &numerator, &denominator);

  printf("In lowest terms: %d/%d\n", numerator, denominator);
  return 0;
}
