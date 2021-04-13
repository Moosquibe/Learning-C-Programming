#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c;
    bool line_empty = true;

    while ((c = getchar()) != EOF) {
      if (!isspace(c))
        line_empty = false;

      if (!line_empty)
        putchar(c);

      if (c == '\n')
        line_empty = true;
 
    }
    return 0;
}