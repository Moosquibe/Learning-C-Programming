#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

void read_line(char *str);

int main(void) {
  char str[MAX_LEN + 1],
       smallest_word[MAX_LEN + 1],
       largest_word[MAX_LEN + 1];

  printf("Enter word: ");
  read_line(str);
  strcpy(smallest_word, str);
  strcpy(largest_word, str);

  while (strlen(str) != 4) {
    printf("Enter word: ");
    read_line(str);

    if (strcmp(str, smallest_word) < 0)
      strcpy(smallest_word, str);
    else if (strcmp(str, largest_word) > 0)
      strcpy(largest_word, str);
  }

  printf("\nSmallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);
  return 0;
}

void read_line(char *str) {
  char c;
  while ((c = getchar()) != '\n') {
    *str++ = c;
  }
  *str = '\0';
}
