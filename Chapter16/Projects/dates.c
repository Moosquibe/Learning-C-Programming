#include <stdio.h>

struct date {
  int month, day, year;
};

int compare_dates(struct date d1, struct date d2) {
  int result;

  if (d1.year < d2.year)
    result = -1;
  else if (d1.year > d2.year)
    result = 1;
  else {
    if (d1.month < d2.month)
      result = -1;
    else if (d1.month > d2.month)
      result = 1;
    else {
      if (d1.day < d2.day)
        result = -1;
      else if (d1.day > d2.day)
        result = 1;
      else
        result = 0;
    }
  }
  return result;
}

int main() {
  struct date date1, date2;
  int month1, day1, year1,
      month2, day2, year2;
  int comparison;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

  comparison = compare_dates(date1, date2);

  switch(comparison) {
    case 0: printf("The dates are the same.\n");
            break;
    case -1: printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
                   date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
            break;
    case 1: printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
                   date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
            break;
  }

  return 0;
}
