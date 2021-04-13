#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
  int orig_char;
  FILE *input, *output;

  if (argc != 3) {
    fprintf(stderr, "Usage: xor <input file> <output file>\n");
    exit(EXIT_FAILURE);
  }

  if ((input = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Input file %s cannot be opened", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((output = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Output file %s cannot be opened", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((orig_char = fgetc(input)) != EOF) {
    fputc(orig_char ^ KEY, output);
  }
  return 0;
}
