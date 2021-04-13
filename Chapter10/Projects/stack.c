#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

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

void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(char c) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = c;
}

char pop(void) {
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}

void stack_overflow(void) {
  printf("Stack overflow");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Parentheses/braces are not nested properly\n");
  exit(EXIT_SUCCESS);
}
