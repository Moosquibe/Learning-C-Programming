#include <stdio.h>

#define MAX_LENGTH 100

int main(void) {
  char current, terminal;
  char sentence[MAX_LENGTH];
  char *rightPos = sentence, *leftPos = sentence;
  char *p;

  printf("Enter a sentence: ");
  *rightPos++ = ' ';
  while((current = getchar())) {
    if ((current == '.') ||
        (current == '?') ||
        (current == '!')) {
      terminal = current;
      break;
    }
    *rightPos++ = current;
  }

  printf("Reversal of sentence: ");

  leftPos = rightPos - 1;
  while (leftPos >= sentence) {
    if (*leftPos == ' ') {
      for(p = leftPos + 1; p < rightPos; p++)
        putchar(*p);

      if (leftPos == sentence)
        putchar(terminal);
      else
        putchar(' ');

      rightPos = leftPos;
    }
    leftPos--;
  }

  printf("\n");
  return 0;
}
