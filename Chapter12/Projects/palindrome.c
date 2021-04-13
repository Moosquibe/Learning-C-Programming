#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main(void) {
  char message[MAX_LENGTH];
  char *p = message, *q = message;

  printf("Enter a message: ");

  while ((*p++ = getchar()) != '\n')
    ;

  p -= 2;

  while (q < p) {
    if (!isalpha(*q)) {
      q++;
      continue;
    }
    if (!isalpha(*p)) {
      p--;
      continue;
    }
    if (tolower(*q) != tolower(*p)) {
      printf("Not a palindrome\n");
      return 0;
    }
    q++;
    p--;
  }

  printf("Palindrome\n");
  return 0;
}
