#include "stack.h"

struct node {
    int value;
    struct node *next;
};

struct node *list;

void make_empty(void) {
  list = NULL;
}

bool is_empty(void) {
  return list == NULL;
}

bool push(int i) {
  struct node *new = (struct node*) malloc(sizeof(struct node));
  if (new == NULL)
    return false;

  new->value = i;
  new->next = list;
  list = new;

  return true;
}

int pop(void) {
  struct node *to_pop = list;
  int ret;

  if (is_empty()) {
    printf("Stack is empty");
    exit(EXIT_FAILURE);
  }
  
  ret = to_pop->value;
  list = to_pop->next;

  free(to_pop);
  return ret;
}

int __count_occurrences(struct node *list, int n) {
  int count = 0;
  struct node *current = list;
  while (current != NULL) {
    if (current->value == n)
      count++;
    
    current = current->next;
  }

  return count;
}

int count_occurrences(int n) {
  return __count_occurrences(list, n);
}

struct node *__find_last(struct node *list, int n) {
  struct node *current = list, *last = NULL;
  while (current != NULL) {
    if (current->value == n)
      last = current;

    current = current->next;
  }

  return last;
}

// Stupid function to test
int *last_n(int n) {
  struct node *last = __find_last(list, n);
  if (last == NULL)
    return NULL;
  return &(last->value);
}


