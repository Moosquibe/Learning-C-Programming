#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  time_t current = time(NULL);
  char time_str[50];

  strftime(time_str, sizeof(time_str), "%A, %B %d, %Y %I:%M", localtime(&current));
  printf("%s%c\n", time_str, localtime(&current)->tm_hour <= 11 ? 'a' : 'p');

  strftime(time_str, sizeof(time_str), "%a, %d %b %Y %H:%M", localtime(&current));
  puts(time_str);

  strftime(time_str, sizeof(time_str), "%m/%d/%Y  %I:%M:%S %p", localtime(&current));
  puts(time_str);

  exit(EXIT_SUCCESS);
}