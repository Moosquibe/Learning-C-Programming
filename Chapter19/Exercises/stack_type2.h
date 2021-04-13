#include <stdbool.h>

#ifndef STACK_TYPE2_H
#define STACK_TYPE2_H

#define STACK_SIZE 100

struct item {
    int value;
    struct item *next;
};

typedef struct item *Stack;

void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);

#endif