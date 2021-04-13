#include <stdio.h>

#define STACK_SIZE 10

/*externals*/

int contents[STACK_SIZE]
int* top_ptr = contents;

void make_empty(void) {
  top_ptr = contents;
}

void is_empty(void) {
  return top_ptr == contents;
}

void is_full(void) {
  return top_ptr == contents + STACK_SIZE - 1;
}

int main(void) {
  return 0;
}
