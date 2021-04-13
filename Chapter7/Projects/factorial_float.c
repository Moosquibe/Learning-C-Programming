#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
  int n;
  long double result = 1;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Number is negative. Exiting...\n");
    exit(1);
  }

  for (int i = 1; i <= n; i++) {
    if (result >  LDBL_MAX / i) {
      printf("Result is larger than %.0Lf, which is the largest I can represent. Exiting...\n", LDBL_MAX);
      exit(1);
    }
    result *= i;
  }

  printf("(Possibly approximate) factorial of %d: %.0Lf\n", n, result);

  return 0;
}
