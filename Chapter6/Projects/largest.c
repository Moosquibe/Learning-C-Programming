#include <stdio.h>
#include <math.h>

int main() {
  float ans, max = -INFINITY;

  do {
    printf("Enter a number: ");
    scanf("%f", &ans);

    if (ans > max) {
      max = ans;
    }
  } while (ans != 0);

  printf("\nThe largest number entered was %f\n", max);
  return 0;
}
