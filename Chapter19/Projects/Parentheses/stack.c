#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"



int main(void) {
  char c;
  bool proper = true;
  Stack s = create();
  printf("Enter parenthesis and/or braces: ");

  while ((c = getchar()) != '\n') {
    switch (c) {
      case '(': case '{':
        push(s, c);
        break;
      case ')':
        if (pop(s) != '(')
          proper = false;
        break;
      case '}':
        if (pop(s) != '{')
          proper = false;
        break;
      default:
        printf("Illegal character: %c\n", c);
        exit(EXIT_FAILURE);
    }
  }

  if (!is_empty(s)) {
    proper = false;
  }

  if (proper)
    printf("Parentheses/braces are nested properly\n");
  else
    printf("Parentheses/braces are not nested properly\n");

  return 0;
}
