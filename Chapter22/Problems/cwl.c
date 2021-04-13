#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;
    int chars = 0, words = 0, lines = 0;
    bool in_word = false;

    if (argc != 2) {
      fprintf(stderr, "Usage: cwl <textfile>\n");
      exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "%s cannot be opened\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fp)) != EOF) {
      chars++;
      if (c == '\n') {
        lines++;
      }
      if (in_word && isspace(c)) {
        in_word = false;
        words++;
      }
      if(!in_word && !isspace(c)) {
        in_word = true;
      }
    }
    printf("Characters: %d, Words: %d, Lines: %d\n", chars, words, lines);
    return 0;
}