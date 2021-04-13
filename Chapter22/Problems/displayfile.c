#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  unsigned char buffer[10]; 
  int bytes_read;

  if (argc != 2) {
    fprintf(stderr, "Usage: displayfile <file>\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  for(int i = 0;; i++) {
    bytes_read = fread(buffer, 1, 10, fp);  
    if (bytes_read == 0)
      break;
    
    printf("%6d  ", i * 10);
    for (int j = 0; j < bytes_read; j++) {
      printf("%.2X ", buffer[j]); 
    }
    for(int j = 0; j < 10 - bytes_read; j++) {
      printf("   ");
    }
    printf(" ");

    for(int j = 0; j < bytes_read; j++) {
      printf(isprint(buffer[j]) ? "%c" : ".", buffer[j]);
    }

    printf("\n");

    if (bytes_read < 10)
      break;
  }

  fclose(fp);
  return 0;
}