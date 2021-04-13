#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c;
    bool prev_space = true;

    while ((c = getchar()) != EOF) {
      if (prev_space && !isspace(c))
        putchar(toupper(c));
      else
        putchar(c);

      if (isspace(c) || c == '\n')
        prev_space = true;
      else 
        prev_space = false; 
    }
    return 0;
}