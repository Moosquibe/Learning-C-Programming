#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct word {
  char *value;
  struct word *next;
};

struct word *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  line = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(char *word)
{
  struct word *new_word;
  struct word *cur, *prev;

  line_len += strlen(word);
  if (num_words > 0) {
    line_len++;
  }

  for (prev = NULL, cur = line; 
       cur != NULL; 
       prev = cur, cur = cur->next)
       ;

  new_word = malloc(sizeof(struct word));
  new_word->value = word;
  new_word->next = NULL;

  if (prev == NULL) {
    line = new_word;
  } else {
    prev->next = new_word;
  }
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;

  struct word *cur_word = line;

  while (cur_word) {
    printf("%s", cur_word->value);

    spaces_to_insert = extra_spaces / (num_words - 1);
    for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');

    extra_spaces -= spaces_to_insert;
    num_words--;
  }

  putchar('\n');
}

void flush_line(void)
{
  struct word *cur_word = line;

  while (cur_word) {
    printf("%s", cur_word->value);
    putchar(' ');
  }
}
