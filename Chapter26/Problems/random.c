#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  for(int i = 0; i < 1000; i++) {
      printf("%d ", rand() % 2);
  }

  printf("\n");
}