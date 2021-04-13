#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
  srand((unsigned) time(NULL));
  char response = 'Y';
  bool win;
  int wins = 0;
  int losses = 0;

  while (toupper(response) == 'Y') {
    win = play_game();
    if (win){
      printf("You win!\n");
      wins++;
    } else {
      printf("You lose!\n");
      losses++;
    }

    printf("\nPlay again? ");
    scanf(" %c", &response);
    printf("\n");
  }

  printf("Wins: %d  Losses: %d\n", wins, losses);
  return 0;
}

int roll_dice(void) {
  int roll = 1 + (abs(rand()) % 6 + abs(rand()) % 6);
  printf("You rolled: %d\n", roll);
  return roll;
}

bool play_game(void) {
  int point = roll_dice();
  int roll;

  switch (point) {
    case 7: case 11: return true;
    case 2: case 3: case 12: return false;
  }

  printf("Your point is: %d\n", point);

  while ((roll = roll_dice()) != point) {
    if (roll == 7)
      return false;
  }

  return true;
}
