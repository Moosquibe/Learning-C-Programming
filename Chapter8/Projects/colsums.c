#include <stdio.h>

#define SIZE 5

int main(void){
  int array[SIZE][SIZE] = {0};
  int row_sum[SIZE], col_sum[SIZE];

  for(int i = 0; i < SIZE; i++) {
    printf("Enter row %d: ", i + 1);
    for(int j=0; j < SIZE; j++){
      scanf(" %d", &array[i][j]);
    }
  }

  for(int i=0; i < SIZE; i++) {
     row_sum[i] = 0; col_sum[i] = 0;
     for(int j=0; j < SIZE; j++) {
       row_sum[i] += array[i][j];
       col_sum[i] += array[j][i];
     }
   }

  printf("\nRow totals: ");
  for(int i = 0; i < SIZE; i++)
    printf("%d ", row_sum[i]);

  printf("\nColumn totals: ");
  for(int i = 0; i < SIZE; i++)
    printf("%d ", col_sum[i]);

  printf("\n");

  return 0;
}
