#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool test_extension(const char *file_name,
                    const char *extension);
void remove_filename(char *url);

int main(void) {
  assert(test_extension("memo.txt", "TXT") == true);
  assert(test_extension("memo.log", "TXT") == false);
  assert(test_extension("memo.log.bz", "TXT") == false);

  char url[] = "http://www.knking.com/index.html";

  remove_filename(url);
  assert(strcmp(url, "http://www.knking.com") == 0);
  return 0;
}

bool test_extension(const char *file_name,
                    const char *extension) {

  const char *p = file_name;

  while (*p)
    p++;

  while (*(--p) != '.') {
    if (p == file_name)
      return strlen(extension) == 0;
  }

  while (*p++) {
    if (toupper(*p) != toupper(*extension++))
      return false;
  }

  return true;
}

void remove_filename(char *url) {
  while (*url++)
    ;

  while (*(--url) != '/')
    ;

  *url = '\0';
}
