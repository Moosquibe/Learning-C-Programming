#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double deposit, rate, years;

  printf("Amount deposited: ");
  scanf("%lf", &deposit);
  printf("Interest rate: ");
  scanf("%lf", &rate);
  printf("Number of years: ");
  scanf("%lf", &years);

  printf("The balance at the end of the period: %.2lf\n", deposit * exp(rate * years));
  exit(EXIT_SUCCESS);
}