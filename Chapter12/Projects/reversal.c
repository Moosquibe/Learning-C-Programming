#include <stdio.h>

#define MAX_LENGTH 100

int main(void) {
  char message[MAX_LENGTH];
  char *p = message;

  printf("Enter a message: ");

  while ((*p++ = getchar()) != '\n')
         ;

  printf("Reversal is: ");

  p -= 2;
  while (p >= message)
    printf("%c", *p--);

  printf("\n");

  return 0;
}
