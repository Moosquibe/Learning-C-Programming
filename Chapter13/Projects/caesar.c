#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 80

void encrypt(char *message, int shift);

int main(void) {
  char current, message[MAX_LENGTH];
  int shift, pos = 0;

  printf("Enter message to be encrypted: ");
  while((current = getchar()) != '\n') {
    message[pos] = current;
    pos++;
  }
  message[pos] = '\0';

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  encrypt(message, shift);

  printf("Encrypted message: %s", message);

  printf("\n");
  return 0;
}

void encrypt(char *message, int shift) {
  while (*message){
    if (isupper(*message))
      *message = ((*message - 'A') + shift) % 26 + 'A';
    else if (islower(*message))
      *message = ((*message - 'a') + shift) % 26 + 'a';
    message++;
  }
}
