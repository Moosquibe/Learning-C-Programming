#include <stdio.h>
#include <stdlib.h>
#include "stack_type.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(Stack *s) {
    s->top = 0;
}

bool isempty(const Stack *s) {
    return s->top == 0;
}

bool is_full(const Stack *s) {
    return s->top == STACK_SIZE;
}
void push(Stack *s, int i) {
    if (is_full(s))
        terminate("Stack is full");
    
    s->contents[(s->top)++] = i;
}

int pop(Stack *s) {
    if (isempty(s))
        terminate("Stack is empty");

    return s->contents[--(s->top)] ;
}
