#include <stdio.h>

int main(void) {
  float balance, rate, payment;
  int no_payments;

  printf("Enter amount of loan: ");
  scanf("%f", &balance);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &payment);
  printf("Enter number of payments: ");
  scanf("%d", &no_payments);

  rate = rate/(12.f * 100.0f);

  printf("\n");

  for (int i = 1; i <= no_payments; i++) {
    balance = balance * (1 + rate) - payment;
    printf("Balance remaining after payment %d: %.2f\n", i, balance);
  }

  return 0;
}
