#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 80

int main(void) {
  char current, message[MAX_LENGTH];
  int shift, pos = 0;

  printf("Enter message to be encrypted: ");
  while((current = getchar()) != '\n') {
    message[pos] = current;
    pos++;
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  printf("Encrypted message: ");
  for(int i = 0; i < pos; i++){
    if (isupper(message[i]))
      message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
    else if (islower(message[i]))
      message[i] = ((message[i] - 'a') + shift) % 26 + 'a';

    putchar(message[i]);
  }

  printf("\n");
  return 0;
}
