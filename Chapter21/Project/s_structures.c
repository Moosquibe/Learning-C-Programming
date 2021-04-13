#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
} str;

int main(void) {
  printf("The size of a is %lu bytes with offset %lu\n", sizeof(str.a), offsetof(struct s, a));
  printf("The size of a is %lu bytes with offset %lu\n", sizeof(str.b), offsetof(struct s, b));
  printf("The size of a is %lu bytes with offset %lu\n", sizeof(str.c), offsetof(struct s, c));
  printf("The size of the entire structure is %lu bytes\n", sizeof(struct s));
}