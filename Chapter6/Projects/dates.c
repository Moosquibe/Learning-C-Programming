#include <stdio.h>
#include <limits.h>

int main() {
  int month, day, year,
      emonth = 12, eday= 31, eyear = INT_MAX;

  while(1) {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month, &day, &year);

    if (month == (day == (year == 0)))
      break;

    if (year < eyear ||
        (year == eyear && month < emonth) ||
        (year == eyear && month == emonth && day < eday)) {
      eyear = year; emonth = month; eday = day;
    }
  }

  printf("%d/%d/%.2d is the earliest date\n", emonth, eday, eyear);

  return 0;
}
