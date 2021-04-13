#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char c;
  if (argc < 2) {
      printf("Usage: fcat <file1> <file2> ...\n");
      exit(EXIT_FAILURE);
  }

  for(int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "%s cannot be opened\n", argv[i]);
      exit(EXIT_FAILURE);
    }
    while ((c = fgetc(fp)) != EOF) {
      putchar(c);
    }
    fclose(fp);
  }
  return 0;
}