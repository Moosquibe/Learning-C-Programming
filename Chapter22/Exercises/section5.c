#include <stdio.h>
#include <assert.h>
#include <string.h>

char *my_fgets(char * restrict s, int n, FILE * restrict stream) {
  char c, *sbak = s;
  int len = 0;

  if (n == 0) {
    return "\0";
  }

  do {
    if ((c = fgetc(stream)) == EOF) {
      if (len == 0 || ferror(stream))
        return NULL;
    }

    *s++ = c;
    len++;
  } while (c != '\n' && len < n);
  *s = '\0';

  return sbak;
}

int my_fputs(const char * restrict s, FILE * restrict stream) {
  while (*s != '\0') {
    if (fputc(*s++, stream) == EOF)
      return EOF;  
  }
  return 0;
}

int main(void) {
  FILE *fp;
  char str[10];
  fp = fopen("./test.txt", "r");

  assert(strcmp(my_fgets(str, 2, fp), "ib") == 0);
  
  fclose(fp);
  fp = fopen("./test2.txt", "w");
  my_fputs("Bela\n", fp);
  fclose(fp);
  return 0;
}