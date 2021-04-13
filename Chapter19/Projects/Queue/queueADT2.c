#include <stdlib.h>
#include <stdio.h>
#include "queueADT2.h"

struct queue_type {
   int *contents;
   int size;
   int front, back;
};

Queue create(int size) {
   Queue q = malloc(sizeof(struct queue_type));
   if (q == NULL) {
       printf("Cannot create queue.");
       exit(EXIT_FAILURE);
   }
   q->contents = malloc(size * sizeof(int));
   if (q->contents == NULL) {
       printf("Cannot create queue.");
       exit(EXIT_FAILURE);
   }
   q->front = 0; q->back = 0;
   q->size = size;
   return q;
}

void destroy(Queue q) {
  free(q->contents);
  free(q);
}

void insert(int item, Queue q) {
   if (q->back == q->front - 1) {
       printf("Cannot insert, queue is full");
       return;
   }

   q->contents[q->back++] = item;
   q->back %= q->size;
}

void rem(Queue q) {
    if (is_empty(q)) {
        printf("Nothing to remove, queue is full");
    }

    q->front++;
    q->front %= q->size;
}

int first(Queue q) {
    return q->contents[q->front];
}
int last(Queue q) {
    return q->contents[q->back - 1];
}

bool is_empty(Queue q) {
    if (q->front == q->back) {
        return true;
    }
    return false;
}