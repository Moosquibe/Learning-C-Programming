#include<stdio.h>

int main(void) {
  int amt, twenties, tens, fives, ones;
  
  printf("Enter a dollar ammount: ");
  scanf("%d", &amt);
  twenties = amt/20; amt -= 20 * twenties;
  tens = amt/10; amt -= 10 * tens;
  fives = amt/5; amt -= 5 * fives;
  ones = amt;
  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}
