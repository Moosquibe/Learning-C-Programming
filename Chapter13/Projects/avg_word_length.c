#include<stdio.h>

#define MAX_SENTENCE_LENGTH 40

double compute_average_word_length(const char *sentence);


int main() {
  char sentence[MAX_SENTENCE_LENGTH];

  printf("Enter a sentence:");
  gets(sentence);

  printf("Average word length: %.1f\n", compute_average_word_length(sentence));

  return 0;
}

double compute_average_word_length (const char *sentence) {
  int word_count = 1, letter_count = 0;

  while (*sentence) {
    if (*sentence == ' ') {
      word_count++;
    } else {
      letter_count++;
    }
    sentence++;
  }

  return (float) letter_count / word_count;
}
