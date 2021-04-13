#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]) {
  int i, j, count, iNew, jNew;

  // Initialize square
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      magic_square[i][j] = 0;

  // Fill square
  i = n / 2;
  j = 0;
  magic_square[i][j] = 1;

  count = 2;
  while (count <= n * n) {
    iNew = (i + 1) % n;
    jNew = (j == 0) ? (n - 1) : (j - 1);

    if (magic_square[iNew][jNew] == 0) {
      i = iNew; j = jNew;
    } else {
      i = i; j = (j + 1) % n;
    }
    magic_square[i][j] = count++;
  }
}

void print_magic_square(int n, char magic_square[n][n]) {
  for(int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++)
      printf("%4d", magic_square[i][j]);
    printf("\n");
  }
}

int main(void){
  int size;

  printf("This probgram creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &size);

  char square[size][size];
  create_magic_square(size, square);
  print_magic_square(size, square);
  return 0;
}
