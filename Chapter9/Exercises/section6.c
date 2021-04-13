#include <stdio.h>
#include <assert.h>

int short_fact(int n) {
  return n <= 1 ? 1 : n * short_fact(n-1);
}

int nonrec_fact(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++ )
    result *= i;

  return result;
}

int rec_gcd(int m, int n) {
  return n == 0 ? m : rec_gcd(n, m % n);
}

void pb(int n) {
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}

int main(void) {
  assert(nonrec_fact(3) == 6);
  assert(rec_gcd(4,6) == 2);

  int n;
  printf("Give me an integer: ");
  scanf("%d", &n);
  pb(n);

  printf("\n");
  return 0;
}
