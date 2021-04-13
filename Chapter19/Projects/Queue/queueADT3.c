#include <stdlib.h>
#include <stdio.h>
#include "queueADT.h"

struct node {
    int data;
    struct node* next;
};

struct queue_type {
    struct node *back;
};

Queue create(void) {
   Queue q = malloc(sizeof(struct queue_type));
   if (q == NULL) {
       printf("Cannot create queue.");
       exit(EXIT_FAILURE);
   }
   return q;
}

void destroy(Queue q) {
  while(!is_empty(q)) {
    rem(q);
  }
  free(q);
}

void insert(int item, Queue q) {
   struct node *new_node = malloc(sizeof(struct node));
   if (new_node == NULL) {
       printf("Cannot insert, queue is full");
       return;
   }
   new_node->data = item;
   new_node->next = q->back;
   q->back = new_node;
}

void rem(Queue q) {
    if (is_empty(q)) {
        printf("Nothing to remove, queue is empty");
    }
    struct node *cur = q->back, *prev = NULL;
    while (cur->next != NULL) {
      prev = cur;
      cur = cur->next;
    }
    
    if (prev != NULL)
      prev->next = NULL;
    else
      q->back = NULL;
    
    free(cur);
}

int first(Queue q) {
    struct node *cur = q->back;
    while (cur->next != NULL) {
      cur = cur->next;
    }
    return cur->data;
}
int last(Queue q) {
    return q->back->data;
}

bool is_empty(Queue q) {
    return q->back == NULL;
}