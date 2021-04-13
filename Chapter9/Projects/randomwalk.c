#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

void generate_random_walk(char walk[SIZE][SIZE]) {
  int x = 0, y = 0, stepCode;
  bool canLeft, canRight, canUp, canDown;
  srand((unsigned) time(NULL));

  // Initialize table
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      walk[i][j] = '.';

  for(char c='A'; c <= 'Z'; c++){
    walk[x][y] = c;

    canLeft = (x != 0) && (walk[x-1][y] == '.');
    canUp = (y != 0) && (walk[x][y-1] == '.');
    canRight = (x != SIZE - 1) && (walk[x+1][y] == '.');
    canDown = (y != SIZE - 1) && (walk[x][y+1] == '.');

    // Stop if there are no more moves left
    if (!(canLeft || canRight || canUp || canDown))
      break;

    // Make the move
    while(true) {
      stepCode = rand() % 4;
      if ((stepCode == 0) && canLeft) {
        x -= 1;
        break;
      } else if ((stepCode == 1) && canRight) {
        x += 1;
        break;
      } else if ((stepCode == 2) && canUp) {
        y -= 1;
        break;
      } else if ((stepCode == 3) && canDown) {
        y += 1;
        break;
      }
    }
  }
}

void print_array(char walk[SIZE][SIZE]){
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++)
      printf("%c ", walk[i][j]);
    printf("\n");
  }
}

int main(void) {
  char table[SIZE][SIZE];

  generate_random_walk(table);
  print_array(table);

  return 0;
}
