#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void) {
  char table[SIZE][SIZE];
  int x = 0, y = 0, stepCode;
  bool canLeft, canRight, canUp, canDown;
  srand((unsigned) time(NULL));

  // Initialize table
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      table[i][j] = '.';

  for(char c='A'; c <= 'Z'; c++){
    table[x][y] = c;

    canLeft = (x != 0) && (table[x-1][y] == '.');
    canUp = (y != 0) && (table[x][y-1] == '.');
    canRight = (x != SIZE - 1) && (table[x+1][y] == '.');
    canDown = (y != SIZE - 1) && (table[x][y+1] == '.');

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

  // Print the table
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++)
      printf("%c ", table[i][j]);
    printf("\n");
  }

  return 0;
}
