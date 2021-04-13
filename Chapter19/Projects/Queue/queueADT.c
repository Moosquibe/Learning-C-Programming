#include <stdlib.h>
#include <stdio.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
   int contents[QUEUE_SIZE];
   int front, back;
};

/*struct node {
    int data;
    struct node* next;
};

struct queue_type {
    struct node *top;
};
*/

Queue create(void) {
   Queue q = malloc(sizeof(struct queue_type));
   if (q == NULL) {
       printf("Cannot create queue.");
       exit(EXIT_FAILURE);
   }
   q->front = 0; q->back = 0;
   return q;
}

void destroy(Queue q) {
  free(q);
}

void insert(int item, Queue q) {
   if (q->back == q->front - 1) {
       printf("Cannot insert, queue is full");
       return;
   }

   q->contents[q->back++] = item;
   q->back %= QUEUE_SIZE;
}

void rem(Queue q) {
    if (is_empty(q)) {
        printf("Nothing to remove, queue is full");
    }

    q->front++;
    q->front %= QUEUE_SIZE;
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