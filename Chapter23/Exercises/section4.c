#include <stdio.h>
#include <math.h>
#include <assert.h>

double evaluate_polynomial(double a[], int n, double x) {
  double val = 0;
  for (int i = 0; i <= n; i++) {
    val = fma(val, x, a[n - i]);
  }
  return val;
}

int main(int argc, char* argv[]) {
  double a[3] = {1, 2, 1};
  assert(evaluate_polynomial(a, 2, 0) == 1.0);
  return 0;
}