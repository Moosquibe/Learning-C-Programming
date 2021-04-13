#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define LENGTH 20

int max(int a[], int n) {
  // Returns the largest element of array
  int max_val = INT_MIN;

  for (int i = 0; i < n; i ++){
    if (a[i] > max_val) {
      max_val = a[i];
    }
  }

  return max_val;
}

float avg(int a[], int n) {
  // Returns average of array elements
  int sum = 0;

  for (int i = 0; i < n; i ++){
    sum += a[i];
  }

  return (float) sum / n;
}

int num_pos(int a[], int n) {
  // Returns the number of positive elements
  // in an array.
  int pos_count = 0;

  for (int i = 0; i < n; i ++){
    if (a[i] > 0) {
      pos_count++;
    }
  }
  return pos_count;
}

float compute_GPA(char grades[], int n) {
  int sum = 0;

  for (int i = 0; i < n; i ++){
    switch(grades[i]) {
      case 'A':
        sum += 4;
        break;
      case 'B':
        sum += 3;
        break;
      case 'C':
        sum += 2;
        break;
      case 'D':
        sum += 1;
        break;
    }
  }

  return (float) sum / n;
}

double inner_product(double a[], double b[], int n) {
  double iprod = 0;

  for (int i = 0; i < LENGTH; i++) {
    iprod += a[i] * b[i];
  }

  return iprod;
}

int evaluate_position(char board[8][8]) {
  int white_sum = 0, black_sum = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      switch(board[i][j]) {
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
  }

  return white_sum - black_sum;
}

int main(void) {
  int a[LENGTH];

  // Exercise 10
  for (int i = 0; i < LENGTH; i++) {
    a[i] = i;
  }

  assert(max(a, LENGTH) == a[LENGTH-1]);
  assert(avg(a, LENGTH) == (float)(LENGTH-1)/2);
  assert(num_pos(a, LENGTH) == LENGTH - 1);

  // Exercise 11
  char grades[] = {'A', 'C', 'F', 'D', 'D', 'A', 'A'};

  assert(compute_GPA(grades, 7) == (float) 16 / 7);

  // Exercise 12
  double b[LENGTH], c[LENGTH];

  for (int i = 0; i < LENGTH; i++) {
    b[i] = i;
    c[i] = 1.0 / LENGTH;
  }

  assert(inner_product(b, c, LENGTH) == (double)(LENGTH - 1)/2);

  // Exercise 13

  char board[8][8] = {[0][4] = 'k', [1][5] = 'b', [7][3] = 'K', [2][3] = 'Q'};

  assert(evaluate_position(board) == 6);

  return 0;
}
