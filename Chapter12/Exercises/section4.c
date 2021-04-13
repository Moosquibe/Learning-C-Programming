#include <stdio.h>
#include <assert.h>

#define N 10
#define LEN 5

int sum_two_dimensional_array(const int a[][LEN], int n) {
  const int *p;
  int sum = 0;

  for (p = &a[0][0]; p <= &a[n-1][LEN-1]; p++) {
    sum += *p;
  }

  return sum;
}

int evaluate_position(char board[8][8]) {
  int white_sum = 0, black_sum = 0;
  const char *p;

  for (p = &board[0][0]; p <= &board[7][7];  p++) {
      switch(*p) {
        case 'Q':
          white_sum += 9;
          break;
        case 'R':
          white_sum += 5;
          break;
        case 'B':
          white_sum += 3;
          break;
        case 'N':
          white_sum += 3;
          break;
        case 'P':
          white_sum += 1;
          break;
        case 'q':
          black_sum += 9;
          break;
        case 'r':
          black_sum += 5;
          break;
        case 'b':
          black_sum += 3;
          break;
        case 'n':
          black_sum += 3;
          break;
        case 'p':
          black_sum += 1;
          break;
      }
    }

  return white_sum - black_sum;
}


int main(void) {
  // Problem 13
  int ident[N][N];
  int *p;

  for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++) {
    if ((p - ident[0]) % (N+1) == 0)
      *p = 1;
    else
      *p = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", ident[i][j]);
    }
    printf("\n");
  }

  // Other problems
  char board[8][8] = {[0][4] = 'k', [1][5] = 'b', [7][3] = 'K', [2][3] = 'Q'};
  assert(evaluate_position(board) == 6);

  int two_dim_array[][5] = {{1, 2, 3, 4, 5},
                            {6, 7, 8, 9, 10}};

    assert(sum_two_dimensional_array(two_dim_array, 2) == 55);

  return 0;
}

