#include <stdio.h>

int main(void){
  int size, count;
  int i, j, iNew, jNew;

  printf("This probgram creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &size);

  // Initialize square
  int square[size][size];
  for(i = 0; i < size; i++)
    for(j = 0; j < size; j++)
      square[i][j] = 0;

  // Fill square
  i = size / 2;
  j = 0;
  square[i][j] = 1;

  count = 2;
  while (count <= size * size) {
    iNew = (i + 1) % size;
    jNew = (j == 0) ? (size - 1) : (j - 1);

    if (square[iNew][jNew] == 0) {
      i = iNew; j = jNew;
    } else {
      i = i; j = (j + 1) % size;
    }
    square[i][j] = count++;
  }

  // Print square

  for(j = 0; j < size; j++) {
    for (i = 0; i < size; i++)
      printf("%4d", square[i][j]);
    printf("\n");
  }

  return 0;
}
