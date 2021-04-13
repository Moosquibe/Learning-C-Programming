#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

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
