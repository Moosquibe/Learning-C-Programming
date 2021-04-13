#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char* argv[]) {
  // Switching to native locale
  setlocale(LC_ALL, "");
  if (strcmp(setlocale(LC_ALL, NULL), "C") == 0)
    printf("Native locale is C\n");
  else
    printf("Native locale is not C\n");
  return 0;   
}