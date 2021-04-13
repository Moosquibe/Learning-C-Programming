#include <stdio.h>

#define MAX_LENGTH 100

void reverse(char *message);

int main(void) {
  char message[MAX_LENGTH + 1];
  char *p = message;

  printf("Enter a message: ");

  while ((*p = getchar()) != '\n')
    p++;
  *p = '\0';

  reverse(message);

  printf("Reversal is: %s\n", message);
  return 0;
}

void reverse(char *message) {
  char *p = message, *q = message, tmp;
  while (*(q+1))
    q++;

  while (p < q) {
    tmp = *p;
    *p = *q;
    *q= tmp;

    p++; q--;
  }
}
