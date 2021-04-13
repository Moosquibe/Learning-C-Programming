#include <stdlib.h>
#include <stdio.h>

void thatsall(void) {
  printf("That's all,");
}

void folks(void) {
    printf(" folks!");
}

int main(int argc, char *argv[]) {
  atexit(folks);
  atexit(thatsall);

  exit(EXIT_SUCCESS);
}