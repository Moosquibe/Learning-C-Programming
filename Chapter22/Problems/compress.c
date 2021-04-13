#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input, *output;
    unsigned char count = 0;
    unsigned char curr_byte, new_byte;

    if (argc != 2) {
        fprintf(stderr, "Usage: compress <file>\n");
        exit(EXIT_FAILURE);
    }

    // Works because of lazy evaluation
    if ((input = fopen(argv[1], "rb")) == NULL ||
        (output = fopen(strcat(argv[1], ".rle"), "wb")) == NULL) {
        fprintf(stderr, "Can't open %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    for(;;) {
        if (fread(&new_byte, sizeof(unsigned char), 1, input) == 0)
            break;

        // In the beginning
        if (count == 0) {
            curr_byte = new_byte;
            count++;
        } else if (new_byte == curr_byte) {
            count++;
        } else {
            fwrite(&count, sizeof(unsigned char), 1, output);
            fwrite(&curr_byte, sizeof(unsigned char), 1, output);

            count = 1;
            curr_byte = new_byte;             
        }
    }
    fclose(input); fclose(output);
    return 0;
}