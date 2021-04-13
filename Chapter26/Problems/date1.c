#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int year, month, day, n;
  time_t dt;
  struct tm date;

  printf("Give me a year: ");
  scanf("%d", &year);
  printf("Give me a month: ");
  scanf("%d", &month);
  printf("Give me a day: ");
  scanf("%d", &day);
  printf("How many days later: ");
  scanf("%d", &n);

  date.tm_sec = date.tm_min = date.tm_hour = 0;
  date.tm_isdst = -1;
  

  date.tm_year = year - 1900;
  date.tm_mon = month - 1;
  date.tm_mday = day + n;

  dt = mktime(&date);

  puts(ctime(&dt));
  exit(EXIT_SUCCESS); 
}