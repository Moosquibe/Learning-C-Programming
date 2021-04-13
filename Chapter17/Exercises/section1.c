#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int n) {
  void *p = malloc(n);
  if (!p) {
      printf("Cannot allocate %d bytes of memory", n);
      exit(EXIT_FAILURE);
  }
  return p;
}

int main(void) {
    int *mem = (int *) my_malloc(INT32_MAX);
    *mem = 12;
    printf("%d\n", *mem);
    
    return 0;
}