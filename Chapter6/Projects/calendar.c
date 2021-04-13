#include <stdio.h>

int main(void) {
  int days, dow_start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &dow_start);

  for(int i=1; i < dow_start; i++)
    printf("   ");

  for(int i=1; i <= days; i++) {
    printf("%2d ", i);
    if ((dow_start-1 + i) % 7 == 0)
      printf("\n");
  }
  printf("\n");
  return 0;
}
