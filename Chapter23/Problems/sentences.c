#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char c;
    bool prev_punct = false;
    int count;

    while ((c = getchar()) != EOF) {
      if (prev_punct && isspace(c))
        count++;

      if (strpbrk(&c, ".?!") != NULL)
        prev_punct = true;
      else
        prev_punct = false;

    }
    if (prev_punct)
      count++;

    printf("The number of sentences: %d\n", count);
    return 0;
}