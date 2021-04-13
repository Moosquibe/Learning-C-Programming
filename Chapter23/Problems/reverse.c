#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    char str[MAX_LENGTH];
    char *p[MAX_LENGTH];
    int count = 1;

    printf("Enter some words: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';

    if ((p[0] = strtok(str, " ")) == NULL) {
      exit(EXIT_SUCCESS);
    }

    while((p[count] = strtok(NULL, " ")) != NULL)
      count++;

    while (--count >= 0) {
       printf("%s\n", p[count]);
    }

    return 0;
}