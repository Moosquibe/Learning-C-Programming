#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *duplicate(char* str) {
    char *p = malloc(strlen(str));
    if (p) {
        strcpy(p, str);
    }
    return p;
}

int main(void) {
    char *s = duplicate("abcd");
    assert(strcmp(s, "abcd") == 0);
    return 0;
}