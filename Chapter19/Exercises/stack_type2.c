#include <stdio.h>
#include <stdlib.h>
#include "stack_type2.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(Stack *s)
{
  while (!is_empty(s))
    pop(s);
}

bool is_empty(const Stack *s)
{
  return *s == NULL;
}

bool is_full(const Stack *s)
{
  return false;
}

void push(Stack *s, int i)
{
  struct item *new_item = malloc(sizeof(struct item));
  if (new_item == NULL)
    terminate("Error in push: stack is full.");

  new_item->value = i;
  new_item->next = *s;
  *s = new_item;
}

int pop(Stack *s)
{
  struct item *old_top;
  int i;

  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  old_top = *s;
  i = (*s)->value;
  *s = (*s)->next;
  free(old_top);
  return i;
}