#include <stdio.h>

#define MAX_WORDS 30
#define MAX_WORD_LENGTH 20

int main(void) {
  char c, terminal, sent_decomp[MAX_WORDS + 1][MAX_WORD_LENGTH + 1] = {};
  int i = 0, j = 0;

  printf("Enter a sentence: ");

  // Burn initial whitespace
  while((c = getchar()) == ' ')
    ;


  do {
    if ((c == '.') || (c == '?') || (c == '!')) {
      // end sentence
      sent_decomp[i++][j] = '\0'; j=0;
      terminal = c;
      break;
    } else if (c != ' ') {
      // store word
      sent_decomp[i][j++] = c;
    } else {
      // end word
      sent_decomp[i++][j] = '\0'; j=0;
    }
  } while((c = getchar()) != '\n' );

  printf("Reversal of sentence: ");

  while(i > 0) {
    printf("%s", sent_decomp[--i]);
    if (i != 0)
      printf(" ");
  }
  printf("%c", terminal);

  printf("\n");
  return 0;
}
