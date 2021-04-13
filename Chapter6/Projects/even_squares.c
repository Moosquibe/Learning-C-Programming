#include <stdio.h>

int main() {
  int n, square;

  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 1; (square = i * i) <= n ; i++) {
    if (square % 2 == 0) {
      printf("%d\n", square);
    }
  }

  return 0;
}
