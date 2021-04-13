#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
  char c;
  bool proper = true;
  printf("Enter parenthesis and/or braces: ");

  while ((c = getchar()) != '\n') {
    switch (c) {
      case '(': case '{':
        push(c);
        break;
      case ')':
        if (pop() != '(')
          proper = false;
        break;
      case '}':
        if (pop() != '{')
          proper = false;
        break;
      default:
        printf("Illegal character: %c\n", c);
        exit(EXIT_FAILURE);
    }
  }

  if (!is_empty()) {
    proper = false;
  }

  if (proper)
    printf("Parentheses/braces are nested properly\n");
  else
    printf("Parentheses/braces are not nested properly\n");

  return 0;
}
