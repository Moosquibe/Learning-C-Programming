#include<stdio.h>

int main() {
  char c;
  int word_count = 1, letter_count = 0;

  printf("Enter a sentence:");

  while ((c = getchar()) != '\n') {
    if (c == ' ') {
      word_count++;
    } else {
      letter_count++;
    }
  }

  printf("Average word length: %.1f\n", (float) letter_count / word_count);

  return 0;
}
