#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOL 0.00001
#define INIT_GUESS 1

int main() {
  double x, old_y, new_y;

  printf("Enter a positive number: ");
  scanf("%lf", &x);

  if (x < 0) {
    printf("Number is negative. Exiting...\n");
    exit(1);
  }

  new_y = INIT_GUESS;

  do {
    old_y = new_y;
    new_y = (old_y + x / old_y) / 2;
  } while (fabs(old_y - new_y) > TOL);

  printf("Square root: %.5lf\n", new_y);
  return 0;
}
