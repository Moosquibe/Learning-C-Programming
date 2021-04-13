#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CR ('\x0d')
#define LF ('\x0a')
#define CZ ('\x1a')

int main(int argc, char *argv[]) {
    FILE *fpin, *fpout;
    char c, d;
    bool prev_CR;

    if (argc != 3) {
        fprintf(stderr, "Usage win2unix <infile> <outfile>\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open input file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fpout = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't write to output file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fread(&c, sizeof(char), 1, fpin) == 1) {
        if (prev_CR && c != LF) {
          d = CR;
          fwrite(&d, sizeof(char), 1, fpout);
        } 

        if (c == CR) {
          prev_CR = true;
        } else {
          prev_CR = false;
          if (c != CZ)
            fwrite(&c, sizeof(char), 1, fpout);
        }
    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}