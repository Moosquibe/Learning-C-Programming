#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_QUEUE_LENGTH 20

// Queue is [front, back)
int contents[MAX_QUEUE_LENGTH];
int front = 0, back = 0, num_elements = 0;

static void terminate(const char * message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

void insert(int item) {
    if (num_elements == MAX_QUEUE_LENGTH)
      terminate("Queue is full");
    
    contents[back] = item;

    back = (back + 1) % MAX_QUEUE_LENGTH;
    num_elements++;
}

void rem(void) {
    if (num_elements == 0)
      terminate("Queue is empty");
  
    front = (front + 1) % MAX_QUEUE_LENGTH;
    num_elements--;
}

int first(void) {
    return contents[front];
}

int last(void) {
    return contents[(back-1) % MAX_QUEUE_LENGTH];
}

bool isempty(void) {
    return front == back;
}

