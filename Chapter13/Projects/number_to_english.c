#include <stdio.h>

int main(void) {
  int first_digit, second_digit;

  const char *singles[] = {"zero",
                           "one",
                           "two",
                           "three",
                           "four",
                           "five",
                           "six",
                           "seven",
                           "eight",
                           "nine"};

  const char *teens[] = {"ten"
                         "eleven",
                         "twelve",
                         "thirteen",
                         "fourteen",
                         "fifteen",
                         "sixteen",
                         "seventeen",
                         "eighteen",
                         "nineteen"};

  const char *tys[] = {"", "",
                       "twenty",
                       "thirty",
                       "fourty",
                       "fifty",
                       "sixty",
                       "seventy",
                       "eighty",
                       "ninety"};

  printf("Enter a two-digit number: ");
  scanf("%1d%1d", &first_digit, &second_digit);
  printf("You entered the number ");

  if (first_digit == 0) {
    printf("%s", singles[second_digit]);
  }
  else if (first_digit == 1) {
    printf("%s", teens[second_digit]);
  } else {
    printf("%s-%s", tys[first_digit], singles[second_digit]);
  }
  printf("\n");
  return 0;
}
