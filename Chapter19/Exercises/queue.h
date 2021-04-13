#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

void insert(int item);
void rem(void);

int first(void);
int last(void);

bool isempty(void);

#endif