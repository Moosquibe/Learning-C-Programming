#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int c);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
  char ch;
  int op1, op2;

  for (;;) {
    printf("Enter an RPN expressions ");
    make_empty();

    for (;;) {
      scanf(" %c", &ch);

      if (isdigit(ch)) {
        push(ch - '0');
      } else if (ch == '=') {
        printf("Value of expression: %d\n", pop());;
        break;
      } else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/'){

        op1 = pop();
        op2 = pop();

        if (ch == '+')
          push(op1 + op2);
        else if (ch == '-')
          push(op2 - op1);
        else if (ch == '*')
          push(op1 * op2);
        else if (ch == '/')
          push(op2 / op1);
      } else {
        exit(EXIT_SUCCESS);
      }
    }
  }
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
