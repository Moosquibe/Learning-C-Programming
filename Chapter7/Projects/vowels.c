#include <stdio.h>
#include <ctype.h>

int main() {
  char c;
  int count = 0;

  printf("Enter a sentence: ");

  while((c = getchar()) != '\n') {
    switch(tolower(c)) {
      case 'a': case 'e': case 'i':
      case 'o': case 'u':
        count++;
        break;
    }
  }

  printf("Your sentence contains %d vowels.\n", count);

  return 0;
}
