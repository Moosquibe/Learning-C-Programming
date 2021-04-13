#include <stdio.h>

int main() {
  int fact=1;
  float eps, term, e = 1;

  printf("When approximating e by Taylor series, stop when the new term is less than: ");
  scanf("%f", &eps);

  for (int i = 1; ; i++) {
    if ((term = 1.0f / fact) < eps)
      break;

    e += term;
    fact *= i + 1;
  }

  printf("The approximation to e: %.5f\n", e);

  return 0;
}
