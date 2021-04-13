/* Formats a file of text */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"


#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
  FILE *fpin, *fpout;
  char word[MAX_WORD_LEN+2];
  int word_len;

  if (argc != 3) {
    fprintf(stderr, "Usage: justify <infile> <outfile>\n");
    exit(EXIT_FAILURE);
  }

  if ((fpin = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fpout = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Can't write to %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN+1, fpin);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(fpout);
      putc('\n', fpout);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(fpout);
      clear_line();
    }
    add_word(word);
  }
}
