#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 50

int compare_words(const void *p, const void *q) {
    return strcmp((char *) p, (char *) q);
}

int main(void) {
  char *words[MAX_WORDS], word[MAX_WORD_LENGTH];
  int num_words = 0;

  for(;;) {
      if (num_words == MAX_WORDS) {
          printf("Out of space");
          break;
      }

      printf("Enter word: ");
      read_line(word, MAX_WORD_LENGTH);

      if (strlen(word) == 0)
        break;

      words[num_words] = malloc(strlen(word)+1);
      if (words[num_words] == NULL) {
        printf("Cannot allocate memory");
        exit(EXIT_FAILURE);
      }
      strcpy(words[num_words], word);
      num_words++;
  }
  
  qsort(words, num_words, sizeof(char*), compare_words);

  for (int i = 0; i < num_words; i++){
      printf("%s ", words[i]);
  }
  printf("\n");
  return 0;
}