#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float result, opnd = 0;
  char op;

  printf("Enter an expression: ");
  scanf("%f", &result);

  while ((op = getchar()) != '\n') {
    scanf("%f", &opnd);
    switch(op) {
      case '+':
        result += opnd;
        break;
      case '-':
        result -= opnd;
        break;
      case '*':
        result *= opnd;
        break;
      case '/':
        result /= opnd;
        break;
      default:
        printf("Illegal expression");
        exit(1);
    }
  }

  printf("Value of expression: %g\n", result);

  return 0;
}
