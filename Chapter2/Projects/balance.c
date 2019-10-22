#include <stdio.h>

int main(void) {
  float balance, rate, payment;

  printf("Enter amount of loan: ");
  scanf("%f", &balance);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &payment);

  rate = rate/(12.f * 100.0f);

  balance = balance * (1 + rate) - payment;
  printf("Balance remaining after first payment: $%.2f\n", balance);
  balance = balance * (1 + rate) - payment;
  printf("Balance remaining after second payment: $%.2f\n", balance);
  balance = balance * (1 + rate) - payment;
  printf("Balance remaining after third payment: $%.2f\n", balance);

  return 0;
}
