#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    FILE *fp;
    char c;
     
    if (argc != 2) {
      printf("Usage: upper <filename>\n");
      exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r+")) == NULL) {
      fprintf(stderr, "Can't open %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fp)) != EOF) {
      putchar(toupper(c));
    }
    return 0;
}