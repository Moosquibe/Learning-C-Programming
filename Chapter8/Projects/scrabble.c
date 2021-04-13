#include <stdio.h>
#include <ctype.h>

int main() {
  int value = 0;
  char c;

  char char_values[26] = {1, 3, 3, 2, 1,
                          4, 2, 4, 1, 8,
                          5, 1, 3, 1, 1,
                          3, 10, 1, 1, 1,
                          1, 4, 4, 8, 4, 10};

  printf("Enter a word: ");

  while((c = toupper(getchar())) != '\n') {
    value += char_values[c - 'A'];
  }
  printf("Scrabble value: %d\n", value);
  return 0;
}
