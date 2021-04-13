
#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
  double a, b, c;
  printf("Give me a: " );
  scanf("%lf", &a);

  printf("Give me b: " );
  scanf("%lf", &b);

  printf("Give me c: " );
  scanf("%lf", &c);

  double discriminant = b * b - 4 * a * c;

  if (discriminant< 0) {
    double complex discriminant_sqrt = csqrt(discriminant);
    double complex root1 = (-b + discriminant_sqrt) / (2 * a);
    double complex root2 = (-b - discriminant_sqrt) / (2 * a);

    printf("root1 = %g %c %gi\n", creal(root1), cimag(root1) < 0 ? '-' : '+' ,fabs(cimag(root1)));
    printf("root2 = %g %c %gi\n", creal(root2), cimag(root2) < 0 ? '-' : '+',fabs(cimag(root2)));
  } else {
    double discriminant_sqrt = sqrt(discriminant);
    double root1 = (-b + discriminant_sqrt) / (2 * a);
    double root2 = (-b - discriminant_sqrt) / (2 * a);

    printf("root1 = %g\n", root1);
    printf("root2 = %g\n", root2);
  }

  return 0;
}
