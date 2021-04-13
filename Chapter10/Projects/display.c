#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

/* external variables */
const int segments[10][7] = {{1, 1, 0, 1, 1, 1, 1},
                             {0, 0, 0, 1, 0, 0, 1},
                             {1, 0, 1, 1, 1, 1, 0},
                             {1, 0, 1, 1, 0, 1, 1},
                             {0, 1, 1, 1, 0, 0, 1},
                             {1, 1, 1, 0, 0, 1, 1},
                             {1, 1, 1, 0, 1, 1, 1},
                             {1, 0, 0, 1, 0, 0, 1},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

const char segment_chars[7] = {'_','|', '_', '|', '|', '_', '|'};

char digits[4][4 * MAX_DIGITS];

/* Prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
  char c;
  int i = 0;

  clear_digits_array();
  printf("Enter a number: ");

  while (i < MAX_DIGITS) {
    if ((c = getchar()) == '\n')
      break;

    if (isdigit(c)) {
      process_digit(c - '0', i++);
    }
  }

  print_digits_array();
}

/***************************************************/
/*  clear_digits: Stores blank characters into all */
/*                elements of digits.              */
/***************************************************/
void clear_digits_array(void) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 * MAX_DIGITS; j++) {
      digits[i][j] = ' ';
    }
  }
}

/***************************************************/
/*  process_digit: Stores seven-segment represen-  */
/*                 tation of digit into a speci-   */
/*                 fied position in digits.        */
/***************************************************/
void process_digit(int digit, int position) {
  char digit_segment_chars[7];
  for (int i = 0; i < 7; i++) {
    if (segments[digit][i] == 0)
      digit_segment_chars[i] = ' ';
    else
      digit_segment_chars[i] = segment_chars[i];
  }

  digits[0][4 * position + 1] = digit_segment_chars[0];

  for (int i = 1; i < 7; i++) {
    digits[i / 4 + 1][4 * position + (i - 1) % 3] = digit_segment_chars [i];
  }
}

/***************************************************/
/*  print_digits_array: Display the rows of digits */
/*                      each on a single line.     */
/***************************************************/
void print_digits_array(void) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 * MAX_DIGITS; j++) {
      putchar(digits[i][j]);
    }
    printf("\n");
  }
}
