#include <stdio.h>

int main(void) {
  int day, month, year;
  char *months[] = {"January",
                    "February",
                    "March",
                    "April",
                    "May",
                    "June",
                    "July",
                    "August",
                    "September",
                    "October",
                    "November",
                    "December"};

  printf("Enter a date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("You entered the date %s %d, %d\n", months[month -1], day, year);
  return 0;
}
