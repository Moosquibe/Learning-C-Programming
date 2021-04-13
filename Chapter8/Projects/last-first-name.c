#include <stdio.h>
#include <ctype.h>

#define MAX_LNAME_LENGTH 20

int main() {
  char c, first_init;
  char last_name[MAX_LNAME_LENGTH] = {0};

  printf("Enter a first and last name: ");

  while ((c = getchar()) == ' ')
    ;

  first_init = toupper(c);

  while ((c = getchar()) != ' ')
    ;

  int i = 0;

  while ((c = getchar()) != '\n') {
    if (c != ' ') {
      last_name[i] = c;
      i++;
    }
  }

  printf("You entered the name: ");
  for(i = 0; last_name[i] != '\0'; i++) {
    printf("%c", last_name[i]); 
  }

  printf(", %c.\n", first_init);
  return 0;
}
