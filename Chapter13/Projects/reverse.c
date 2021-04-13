#include <stdio.h>

int main(int argc, char *argv[]) {
  char **p = &argv[1];

  while (*p)
    p++;

  while (--p >= &argv[1]) {
    printf("%s ", *p);
  }

  printf("\n");
  return 0;
}
