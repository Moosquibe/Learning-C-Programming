#include <stdio.h>

float tax_due(float income) {
  float tax;
  if (income < 750)
    tax = income * 0.01f;
  else if (income < 2250)
    tax = 7.5f + (income - 750) * 0.02f;
  else if (income < 3750)
    tax = 37.5f + (income - 2250) * 0.03f;
  else if (income < 5250)
    tax = 82.50f + (income - 3750) * 0.04f;
  else if (income < 7000)
    tax = 142.50f + (income - 5250) * 0.05f;
  else
    tax = 230.0f + (income - 7000) * 0.06f;

  return tax;
}

int main() {
  float income;

  printf("Enter taxable income: ");
  scanf("%f", &income);

  printf("Tax due: %.2f\n", tax_due(income));

  return 0;
}
