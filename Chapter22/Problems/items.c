#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_LINE 100

int main(int argc, char *argv[]) {
  FILE *fp;
  char line[MAX_LINE];
  int item, month, day, year;
  float price;

  if (argc != 2) {
    fprintf(stderr, "Usage items <item list csv>");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  while (fread_line(line, MAX_LINE, fp)) {
    sscanf(line, "%d,%f,%d/%d/%d", &item, &price, &month, &day, &year);
    printf("%d\t\t$ %6.2f\t%d/%d/%d\n", item, price, month, day, year);
  }
  
  return 0;
}