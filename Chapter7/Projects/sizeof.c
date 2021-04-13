#include <stdio.h>

int main() {
  printf("sizeof(int): %d bytes\n", (unsigned) sizeof(int));
  printf("sizeof(short): %d bytes\n", (unsigned) sizeof(short));
  printf("sizeof(long): %d bytes\n", (unsigned) sizeof(long));
  printf("sizeof(float): %d bytes\n", (unsigned) sizeof(float));
  printf("sizeof(double): %d bytes\n", (unsigned) sizeof(double));
  printf("sizeof(long double): %d bytes\n", (unsigned) sizeof(long double));

  return 0;
}
