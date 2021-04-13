#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "stackADT.h"

int main(void) {
  Stack s = create();
  char ch;
  int op1, op2;

  for (;;) {
    printf("Enter an RPN expressions ");
    make_empty(s);

    for (;;) {
      scanf(" %c", &ch);

      if (isdigit(ch)) {
        push(s, ch - '0');
      } else if (ch == '=') {
        printf("Value of expression: %d\n", pop(s));;
        break;
      } else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/'){

        op1 = pop(s);
        op2 = pop(s);

        if (ch == '+')
          push(s, op1 + op2);
        else if (ch == '-')
          push(s, op2 - op1);
        else if (ch == '*')
          push(s, op1 * op2);
        else if (ch == '/')
          push(s, op2 / op1);
      } else {
        exit(EXIT_SUCCESS);
      }
    }
  }
}