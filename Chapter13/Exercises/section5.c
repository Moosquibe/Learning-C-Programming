#include <stdio.h>
#include <assert.h>
#include <string.h>

int my_strcmp(const char *s, const char *t) {
  while (*s == *t) {
    if (*s == '\0')
      return 0;
    s++; t++;
  }
  return *s - *t;
}

void get_extension(const char *file_name, char *extension) {
  const char *p = file_name + strlen(file_name) - 1;
  for (; *p != '.' && p > file_name; p--)
    ;
  if (p > file_name)
    strcpy(extension, p+1);
  else
    strcpy(extension, "");
}

void build_index_url(const char *domain, char *index_url) {
  strcpy(index_url, "http://www.");
  strcat(index_url, domain);
  strcat(index_url, "/index.html");
}

int main(void) {
  assert(my_strcmp("ab", "bb") < 0);
  assert(my_strcmp("aa", "aa") == 0);

  char extension[4];
  get_extension("manifest.txt", extension);
  assert(strcmp(extension, "txt") == 0);
  get_extension("manifest", extension);
  assert(strcmp(extension, "") == 0);

  char domain[] = "knking.com";
  char index_url[20];
  build_index_url(domain, index_url);
  assert(strcmp(index_url, "http://www.knking.com/index.html") == 0);
  return 0;
}
