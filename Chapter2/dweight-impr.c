#include <stdio.h>

int main(void) {
  int height=8, length=12, width=10;

  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (Cubic inches): %d\n", height * width * length);
  printf("Dimensional weight (pounds): %d\n", (height * width * length + 165)/166);

  return 0;
}
