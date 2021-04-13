#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int line_length(const char *filename, int n) {
  FILE *fp;
  int len;
  char c;

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  len = 0;
  for (int i = 0; i < n; i++) {
    while((c = fgetc(fp)) != '\n') {
      if (c == EOF) {
        fclose(fp); 
        return 0;
      }
      if (i == n-1)
        len++;
    }
  }
  fclose(fp);
  return len;
}

int main(void) {
  assert(line_length("test.txt", 3) == 5);
  assert(line_length("test.txt", 5) == 0);
}