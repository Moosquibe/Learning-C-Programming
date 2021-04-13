#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c;

    while ((c = getchar()) != EOF) {
      if (iscntrl(c) && c != '\n')
        putchar('?');
      else
        putchar(c);
    }
    return 0;
}