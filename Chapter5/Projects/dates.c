#include <stdio.h>

int main() {
  int month1, day1, year1,
      month2, day2, year2;
  int earlier;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month1, &day1, &year1);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month2, &day2, &year2);

  if (year1 < year2) {
    earlier = 1;
  } else if (year1 > year2) {
    earlier = 2;
  } else {
    if (month1 < month2) {
      earlier = 1;
    } else if (month1 > month2) {
      earlier = 2;
    } else {
      if (day1 < day2) {
        earlier = 1;
      } else if (day1 > day2) {
        earlier = 2;
      } else {
        earlier = 0;
      }
    }
  }

  switch(earlier) {
    case 0: printf("The dates are the same.\n");
            break;
    case 1: printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
                   month1, day1, year1, month2, day2, year2);
            break;
    case 2: printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
                   month2, day2, year2, month1, day1, year1);
            break;
  }

  return 0;
}
