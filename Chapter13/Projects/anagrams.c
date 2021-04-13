#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ABC_SIZE 26
#define MAX_WORD_SIZE 20

bool are_anagrams(const char *word1, const char *word2);

int main(void){
  char word1[MAX_WORD_SIZE], word2[MAX_WORD_SIZE];

  printf("Enter first word: ");
  scanf("%s", word1);

  printf("Enter second word: ");
  scanf("%s", word2);

  if (are_anagrams(word1, word2))
    printf("The words are anagrams.\n");
  else
    printf("The words are not anagrams.\n");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
  int chars[ABC_SIZE] = {0};
  bool anagrams = true;

  while(*word1) {
    if (isalpha(*word1))
      chars[tolower(*word1) - 'a']++;
    word1++;
  }
  while (*word2) {
    if (isalpha(*word2))
      chars[tolower(*word2) - 'a']--;
    word2++;
  }
  for(int i = 0; i < ABC_SIZE; i++)
    if (chars[i] != 0)
      anagrams = false;

  return anagrams;
}
