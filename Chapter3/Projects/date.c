#include <stdio.h>

int main(void) {
  int month, day, year;
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("%d%2.2d%2.2d", year, month, day);
  return 0;
}
