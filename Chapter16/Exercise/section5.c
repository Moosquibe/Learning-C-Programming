#include <stdio.h>

// Problem 18
typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {BLACK, WHITE} Color;

struct Square {
  Piece piece;
  Color color;
};

struct Square board[8][8] = {
  {{ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE}, {KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}},
  {{PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}},
  {{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
  {{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
  {{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
  {{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
  {{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}},
  {{ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}}};

// Problem 19
struct pinball_machine {
  char name[40];
  int year;
  enum {EM, SS} type;
  int players;
};

// Problem 20
enum {NORTH, SOUTH, EAST, WEST} direction = EAST;
int x = 0, y = 0;

switch (direction) {
  case NORTH:
    y++;
    break;
  case SOUTH:
    y--;
    break;
  case EAST:
    x++;
    break;
  case WEST:
    x--;
    break;
}

// Problem 22
enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

const int piece_value[] = {200, 9, 5, 3, 3, 1};
const int piece_value2[] = {
  [KING] = 200,
  [QUEEN] = 9,
  [ROOK] = 5,
  [BISHOP] = 3,
  [KNIGHT] = 3,
  [PAWN] = 1
};

int main(void) {
  return 0;
}
