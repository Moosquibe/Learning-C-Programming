#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n;
  unsigned long long result = 1;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Number is negative. Exiting...\n");
    exit(1);
  }

  for (int i = 1; i <= n; i++) {
    if (result >  ULLONG_MAX / i) {
      printf("Result is larger than %llu, which is the larges I can represent. Exiting...\n", ULLONG_MAX);
      exit(1);
    }
    result *= i;
  }

  printf("Factorial of %d: %lld\n", n, result);

  return 0;
}
