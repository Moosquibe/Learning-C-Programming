#include <stdio.h>

int main(void) {
  int m, n, rem;

  printf("Enter two positive integers: ");
  scanf("%d%d", &n, &m);

  while (n % m != 0) {
    rem = n % m;
    n = m;
    m = rem;
  }
  printf("Greatest common divisor: %d\n", m);
  return 0;
}
