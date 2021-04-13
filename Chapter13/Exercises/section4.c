#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

void capitalize(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
}

void capitalize_ptrs(char *str) {
  while (*str) {
    *str = toupper(*str);
    str++;
  }
}

void censor(char *str) {
  while (*str) {
    if (*str == 'f' && *(str + 1) == 'o' && *(str+2) == 'o') {
      *str = *(str + 1) = *(str + 2) = 'x';
    }
    str++;
  }
}

int main(void) {
  char str[] = "abrak";
  capitalize(str);
  assert(strcmp(str, "ABRAK") == 0);

  char str2[] = "abrak";
  capitalize_ptrs(str2);
  assert(strcmp(str2, "ABRAK") == 0);

  char str3[] = "food fool";
  censor(str3);
  assert(strcmp(str3, "xxxd xxxl") == 0);

  return 0;
}
