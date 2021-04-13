#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ABC_SIZE 26

void read_word(int counts[ABC_SIZE]){
  char ch;

  while((ch = getchar()) != '\n') {
    if (isalpha(ch))
      counts[tolower(ch) - 'a']++;
  }
}

bool equal_array(int counts[ABC_SIZE], int counts2[ABC_SIZE]) {
  for(int i = 0; i < ABC_SIZE; i++)
    if (counts[i] != counts2[i])
      return false;

  return true;
}

int main(void){
  char ch;
  int word1[ABC_SIZE] = {0}, word2[ABC_SIZE] = {0};
  bool anagrams = true;

  printf("Enter first word: ");
  read_word(word1);

  printf("Enter second word: ");
  read_word(word2);

  anagrams = equal_array(word1, word2);

  if (anagrams)
    printf("The words are anagrams.\n");
  else
    printf("The words are not anagrams.\n");

  return 0;
}
