#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(void)
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card, duplicate;
  int cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    duplicate = false;
    for (int i = 0; i <= cards_read; i++) {
      if (rank == hand[i][0] && suit == hand[i][1]) {
        duplicate = true;
      }
    }

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (duplicate)
      printf("Duplicate card; ignored.\n");
    else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(void)
{
  straight = true;
  flush = true;
  four = false;
  three = false;
  pairs = 0;

  /* sort cards by insertion sort*/
  int max_ind, temp_rank, temp_suit;
  for (int i = 0; i < NUM_CARDS - 1; i++) {
    max_ind = 0;
    for (int j = 0; j < NUM_CARDS - i; j++) {
      if (hand[j][0] > hand[max_ind][0]) {
        max_ind = j;
      }
    }
    temp_rank = hand[max_ind][0];
    temp_suit = hand[max_ind][1];
    hand[max_ind][0] = hand[NUM_CARDS - i-1][0];
    hand[max_ind][1] = hand[NUM_CARDS - i-1][1];
    hand[NUM_CARDS - i-1][0] = temp_rank;
    hand[NUM_CARDS - i-1][1] = temp_suit;
  }

  /* check for flush */
  int suit = hand[0][1];
  for (int i = 0; i < NUM_CARDS; i++){
    if (hand[i][1] != suit)
      flush = false;
  }

  /* check for straight */
  for (int i = 1; i < NUM_CARDS; i++)
    if (hand[i][0] != hand[i-1][0] + 1)
      straight = false;

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  int run_length = 1;
  for (int i = 1; i < NUM_CARDS; i++) {
    if (hand[i][0] == hand[i-1][0])
      run_length++;

    if (hand[i][0] != hand[i-1][0] || i == NUM_CARDS - 1) {
      switch (run_length) {
        case 2:
          pairs++;
          break;
        case 3:
          three = true;
          break;
        case 4:
          four = true;
          break;
      }
      run_length = 1;
    }
  }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
  if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");

  printf("\n\n");
}
