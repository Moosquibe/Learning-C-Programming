#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_type *Queue;

Queue create(void);
void destroy(Queue q);

void insert(int item, Queue q);
void rem(Queue q);

int first(Queue q);
int last(Queue q);

bool is_empty(Queue q);

#endif