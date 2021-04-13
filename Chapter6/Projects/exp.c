#include <stdio.h>

int main() {
  int n, fact=1;
  float e = 1;

  printf("Number of terms in Taylor series (0 is the constant term): ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    e += 1.0f / fact;
    fact *= i + 1;
  }

  printf("The approximation to e: %.5f\n", e);

  return 0;
}
