#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct item {
    int value;
    struct item *next;
};

static struct item *front, *back;

static void terminate(const char * message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

void insert(int item) {
    struct item *new_item = malloc(sizeof(struct item));
    if (new_item == NULL)
      terminate("Queue full");
    
    new_item->value = item;
    new_item->next = NULL;

    if (back == NULL) {
        front = back = new_item;
    } else {
        back->next = new_item;
        back = new_item;
    }
}

void rem(void) {
    if (isempty())
      terminate("Queue is empty");
  
    struct item *old_front = front;
    front = front->next;
    free(old_front);
}

int first(void) {
    return front->value;
}

int last(void) {
    return back ->value;
}

bool isempty(void) {
    return front == NULL;
}