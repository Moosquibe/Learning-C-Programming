#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 100

typedef struct {
    int contents[QUEUE_SIZE];
    int back, front, num_elements;
} Queue;

void insert(int item, Queue *q);
void rem(Queue *q);

int first(Queue *q);
int last(Queue *q);

bool isempty(Queue *q);

#endif