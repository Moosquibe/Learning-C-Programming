#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#define TRY_MATH_FNC(f, x) (try_math_fnc(f, x, "#f"))

double try_math_fnc(double (*f)(double), double x, char *msg) {
  double result;
  errno = 0;

  result = (*f)(x);
  if (errno != 0) {
    perror(msg);
    exit(EXIT_FAILURE);
  }

  return result;
}

int main(int argc, char *argv[]){
  try_math_fnc(sqrt, -10, "Error in call of sqrt");
  TRY_MATH_FNC(exp, 10000000);
  TRY_MATH_FNC(log, -3);
  return 0;
}