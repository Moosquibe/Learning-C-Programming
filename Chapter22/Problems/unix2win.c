#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    FILE *fpin, *fpout;
    char c;
    bool prev_car_ret;

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
        if (c == '\x0a') {
          fwrite("\x0d", sizeof(char), 1, fpout);
          fwrite("\x0a", sizeof(char), 1, fpout);
        } else if (c == EOF) {
          fwrite("\x1a", sizeof(char), 1, fpout);
        } else {
          fwrite(&c, sizeof(char), 1, fpout);
        }
    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}