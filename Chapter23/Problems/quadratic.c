#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
  double a,b,c, disc;

  printf("Give me a: ");
  scanf(" %lf", &a);
  printf("Give me b: ");
  scanf(" %lf", &b);
  printf("Give me c: ");
  scanf(" %lf", &c);

  disc = b * b - 4 * a * c;
  if (disc < 0) {
    printf("Discriminant negative, no real solution\n");
  } else {
    printf("x1: %lf\n", (-b + sqrt(disc)) / (2 * a));
    printf("x2: %lf\n", (-b - sqrt(disc)) / (2 * a));
  }

  return 0;
}