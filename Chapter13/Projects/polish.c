#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

/* function declarations */
int evaluate_RPN_expression(const char *expression);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int c);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
  char ch, expression[STACK_SIZE];
  int i, value;

  for (;;) {
    printf("Enter an RPN expressions ");

    i = 0;
    while ((ch = getchar()) != '\n') {
      expression[i++] = ch;
    }
    expression[i] = '\0';

    value = evaluate_RPN_expression(expression);
    printf("Value of expression: %d\n", value);
  }
}

int evaluate_RPN_expression(const char *expression) {
  int op1, op2, value;
  make_empty();
  for (;;) {

    if (isdigit(*expression)) {
      push(*expression - '0');
    } else if (*expression == '=') {
      value = pop();
      break;
    } else if (*expression == '+' || *expression == '-' ||
               *expression == '*' || *expression == '/'){

      op1 = pop();
      op2 = pop();

      if (*expression == '+')
        push(op1 + op2);
      else if (*expression == '-')
        push(op2 - op1);
      else if (*expression == '*')
        push(op1 * op2);
      else if (*expression == '/')
        push(op2 / op1);
    } else if (*expression != ' ') {
      exit(EXIT_SUCCESS);
    }
    expression++;
  }
  return value;
}

void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(int c) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = c;
}

int pop(void) {
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}

void stack_overflow(void) {
  printf("Expression too complex");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression");
  exit(EXIT_FAILURE);
}
