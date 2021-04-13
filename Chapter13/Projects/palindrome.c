#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool is_palindrome(const char *message);

int main(void) {
  char message[MAX_LENGTH];
  char *p = message;
  bool palindrome;

  printf("Enter a message: ");
  while ((*p = getchar()) != '\n')
    p++;
  *p = '\0';

  palindrome = is_palindrome(message);
  if (palindrome)
    printf("Palindrome\n");
  else
    printf("Not palindrome\n");
  return 0;
}

bool is_palindrome(const char *message) {
  const char *p = message, *q = message;
  bool palindrome = true;

  while (*(p+1))
    p++;

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
      palindrome = false;
    }
    q++;
    p--;
  }

  return palindrome;
}
