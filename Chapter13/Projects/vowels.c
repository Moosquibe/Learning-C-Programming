#include <stdio.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 40

int compute_vowel_count(const char *sentence);

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  int count;

  printf("Enter a sentence: ");
  gets(sentence);

  count = compute_vowel_count(sentence);
  printf("Your sentence contains %d vowels.\n", count);

  return 0;
}

int compute_vowel_count(const char *sentence) {
  int count = 0;
  while(*sentence){
    switch(tolower(*sentence)) {
      case 'a': case 'e': case 'i':
      case 'o': case 'u':
        count++;
        break;
    }
    sentence++;
  }

  return count;
}
