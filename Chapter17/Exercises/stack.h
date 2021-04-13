#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

void make_empty(void);
bool is_empty(void);
bool push(int i);
int pop(void);
int count_occurrences(int n);
int *last_n(int n);

#endif