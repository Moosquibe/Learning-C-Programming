#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int area_code, first3, last4, i = 0;
  char c, num_string[11];

  if (argc != 2) {
    fprintf(stderr, "Usage: phoneno <phoneno-file>\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s", argv[1]);
    exit(EXIT_FAILURE);
  }
  
  while((c = getc(fp)) != EOF) {
    if (isdigit(c)) {
      num_string[i] = c;
      i++;
    }    
    if (c == '\n') {
        num_string[i] = '\0';
        sscanf(num_string, "%3d%3d%4d", &area_code, &first3, &last4);
        printf("(%d) %d-%d\n", area_code, first3, last4);
        i = 0;
    }
  }
  fclose(fp);
   
  return 0;
}