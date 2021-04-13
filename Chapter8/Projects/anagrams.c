#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ABC_SIZE 26

int main(void){
  char ch;
  int chars[ABC_SIZE] = {0};
  bool anagrams = true;

  printf("Enter first word: ");
  while((ch = getchar()) != '\n') {
    if (isalpha(ch))
      chars[tolower(ch) - 'a']++;
  }

  printf("Enter second word: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch))
      chars[tolower(ch) - 'a']--;
  }

  for(int i = 0; i < ABC_SIZE; i++)
    if (chars[i] != 0)
      anagrams = false;

  if (anagrams)
    printf("The words are anagrams.\n");
  else
    printf("The words are not anagrams.\n");

  return 0;
}
