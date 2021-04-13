#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH_NAME 40

void reverse_name(char *name);

int main() {
  char name[MAX_LENGTH_NAME];
  printf("Enter a first and last name: ");
  gets(name);

  reverse_name(name);

  return 0;
}

void reverse_name(char *name) {
  char first_init;
  while (*name == ' ')
    name++;

  first_init = toupper(*name);

  while (*name != ' ')
    name++;

  while (*name != '\0') {
    if (*name != ' ')
      printf("%c", *name);
    name++;
  }

  printf(", %c.\n", first_init);
}
