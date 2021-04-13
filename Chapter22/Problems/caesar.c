#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char fnin[FILENAME_MAX], fnout[FILENAME_MAX], c;
  int shift, pos = 0;
  FILE *fpin, *fpout;

  printf("Enter name of file to be encrypted: ");
  scanf("%s", fnin);

  if ((fpin = fopen(fnin, "r")) == NULL) {
    fprintf(stderr, "Can't open file %s", fnin);
    exit(EXIT_FAILURE);
  }

  strcpy(fnout, fnin);
  strcat(fnout, ".enc");

  if ((fpout = fopen(fnout, "w")) == NULL) {
    fprintf(stderr, "Can't write to file %s", fnout);
    exit(EXIT_FAILURE);
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  while ((c = getc(fpin)) != EOF) {
    if (isupper(c)) {
      putc(((c - 'A') + shift) % 26 + 'A', fpout);
    } else if (islower(c)) {
      putc(((c - 'a') + shift) % 26 + 'a', fpout); 
    } else {
      putc(c, fpout);
    }
  }

  fclose(fpin);
  fclose(fpout);

  return 0;
}
