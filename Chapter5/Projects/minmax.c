#include <stdio.h>

int main() {
  int a1, a2, a3, a4,
      min12, max12,
      min34, max34,
      min, max;

  printf("Enter four integers: ");
  scanf("%d %d %d %d", &a1, &a2, &a3, &a4);

  if (a1 < a2) {
    min12 = a1;
    max12 = a2;
  } else {
    min12 = a2;
    max12 = a1;
  }

  if (a3 < a4) {
    min34 = a3;
    max34 = a4;
  } else {
    min34 = a4;
    max34 = a3;
  }

  if (max12 < max34) {
    max = max34;
  } else {
    max = max12;
  }

  if (min12 < min34) {
    min = min12;
  } else {
    min = min34;
  }

  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);

  return 0;
}
