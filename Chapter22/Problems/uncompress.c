#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input, *output;
    unsigned char byte, count = 0;
    char *p, *outfile;

    if (argc != 2) {
        fprintf(stderr, "Usage: uncompress <compressed file>\n");
        exit(EXIT_FAILURE);
    }

    p = argv[1];
    while (*p)
        p++;
    while(p > argv[1] && *p != '.')
        p--;
    if (strcmp(p, ".rle") != 0) {
        fprintf(stderr, "Compressed file does not end in .rle");
        exit(EXIT_FAILURE);
    }
    outfile = malloc((strlen(argv[1]) - 4) * sizeof(char));
    strncpy(outfile, argv[1], strlen(argv[1]) - 4);

    if ((input = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((output = fopen(outfile, "wb")) == NULL) {
        fprintf(stderr, "Can't write %s", outfile);
        exit(EXIT_FAILURE);
    }

    for(;;) {
        if ((fread(&count, sizeof(unsigned char), 1, input) == 0) ||
            (fread(&byte, sizeof(unsigned char), 1, input) == 0))
            break;

        for (int i = 0; i < count; i++) {
            fwrite(&byte, sizeof(unsigned char), 1, output);
        }
    }
    fclose(input); fclose(output);
    return 0;
}