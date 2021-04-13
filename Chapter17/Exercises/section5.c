#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// Problem 4
struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

// Problem 6
struct node {
  int value;
  struct node *next;
};

struct node *delete_from_list(struct node *list, int n) {
  struct node *prev, *garbage; // Ok, not exactly one pointer
  prev->value = 0; 
  prev->next = list;

  while (prev->next != NULL && prev->next->value != n)
    prev = prev->next;
  
  if (prev->next == NULL)
    return list;
  else if (prev->next == list)
    return list->next;
  else {
    garbage = prev->next;
    prev->next = prev->next->next;
    free(garbage);
  }
  return list;
}

// Problem 10
struct part {
  int number;
  char name[15];
  int on_hand;
};

void print_part(struct part *p) {
  printf("Part number: %d\n", p->number);
  printf("Part name: %s\n", p->name);
  printf("Quantity on hand: %d\n", p->on_hand);
}

int main(void) {
  struct rectangle *p = malloc(sizeof(struct rectangle));
  p->upper_left = (struct point) {.x=15, .y=25};
  p->lower_right = (struct point) {.x=20, .y=15};  

  push(3);
  push(4);
  push(3);
  push(2);
  assert(pop() == 2);

  struct part pt = {.on_hand = 10,
                   .name = "Disk drive",
                   .number = 528};

  print_part(&pt);

  assert(count_occurrences(3) == 2);

  assert(*(last_n(4)) == 4);
  return 0; 
}