#include <stdio.h>
#include <ctype.h>

int main() {
  char c, first_init;
  printf("Enter a first and last name: ");

  while ((c = getchar()) == ' ')
    ;

  first_init = toupper(c);

  while ((c = getchar()) != ' ')
    ;

  while ((c = getchar()) != '\n') {
    if (c != ' ')
      putchar(c);
  } 

  printf(", %c.\n", first_init);
  return 0;
}
