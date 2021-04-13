#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 300

int main(void) {
  char ch, msg[MAX_LENGTH];
  int length = 0;

  printf("Enter message: ");
  while ((ch = getchar()) != '\n' && length < MAX_LENGTH) {
    msg[length] = ch;
    length++;
  }

  printf("In B1FF speak: ");
  for(int i=0; i < length; i++) {
    ch = toupper(msg[i]);
    switch (ch) {
      case 'A':
        putchar('4');
        break;
      case 'B':
        putchar('8');
        break;
      case 'E':
        putchar('3');
        break;
      case 'I':
        putchar('1');
        break;
      case 'O':
        putchar('0');
        break;
      case 'S':
        putchar('5');
        break;
      default:
        putchar(ch);
    }
  }
  printf("!!!!!!!!!!!!\n");
}
