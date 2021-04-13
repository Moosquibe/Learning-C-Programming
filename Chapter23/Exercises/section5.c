#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool is_c_indentifier(char *str) {
  if (!isalpha(str[0]) && (str[0] != '_')) 
    return false;

  for (char  *p = &str[1]; *p; p++) {
    if (!isalnum(*p) && *p != '_')
      return false;
  }
  return true;
}

long int is_hexa(char *str) {
  char *p = str;

  while (*p) {
    if (!isxdigit(*p))
      return -1;
    p++;
  }

  return strtol(str ,NULL,16);
}


int main(int argc, char* argv[]) {
  assert(is_c_indentifier("9gag") == false);
  assert(is_c_indentifier("_bla9_") == true);

  assert(is_hexa("AB") == 171);
  assert(is_hexa("AG") == -1);
}