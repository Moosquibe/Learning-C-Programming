/* Finds repeated digits in a number */
#include<stdio.h>
#include<stdbool.h>

int main(void) {
  int digit_seen[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_seen[digit] += 1;
    n /= 10;
  }

  printf("\nRepeated digit(s): ");
  for(int i = 0; i < 10; i++)
    if (digit_seen[i] > 1)
      printf("%d ", i);

  printf("\n");
  return 0;
}
