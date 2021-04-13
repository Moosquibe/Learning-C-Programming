#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int numchar(const char *s, char ch){
  char *p = (char*) s;
  int count = 0;

  while((p = strchr(p, ch)) != NULL) {
    count++;
    p++;
  }

  return count;
}

char *my_strdup(const char *s) {
  char* dup;

  if ((dup = malloc((strlen(s) + 1) * sizeof(char))) != NULL) {
    strcpy(dup, s);
  }
  return dup;
}

int my_stricmp(const char *s1, const char *s2) {
  int len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);

  for(int i = 0; i < len; i++) {
    if (toupper(s1[i]) < toupper(s2[i]))
      return -1;
    else if (toupper(s1[i]) > toupper(s2[i]))
      return 1;
  }

  return 0;
}

char *my_strlwr(char *s) {
  char *p = s;
  while (*p) {
    *p = tolower(*p);
    p++;
  }
  return s;
}

char *my_strrev(char *s) {
  char tmp, *p=s;
  int len = strlen(s);

  for (int i = 0; i < len / 2; i++) {
    tmp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = tmp;
  }

  return p;
}

char *strset(char *s, char ch) {
  for (int i = 0; i < strlen(s); i++)
    s[i] = ch;

  return s;
}

int num_words(char *sentence) {
    int count = 1;

    if (strtok(sentence, " \t\r\n\v\f") == NULL)
      return 0;
    
    while (strtok(NULL, " \t\r\n\v\f") != NULL)
      count++;

    return count;
}

int main(int argc, char* argv[]) {
    assert(numchar("Balbalba", 'b') == 2);
    assert(numchar("Balbalba", 'c') == 0);

    char test[] = "Baaa";
    char *dup_test = my_strdup(test);
    assert(strcmp(dup_test, test) == 0);
    assert(my_stricmp("Baaa", "BAAA") == 0);
    assert(strcmp(my_strlwr(dup_test), "baaa") == 0);
    assert(strcmp(my_strrev(dup_test), "aaab") == 0);
    assert(strcmp(strset(test, 'o'), "oooo") == 0);

    char test2[] = "The elephant went to the market";

    assert(num_words(test2) == 6);

    return 0;
}