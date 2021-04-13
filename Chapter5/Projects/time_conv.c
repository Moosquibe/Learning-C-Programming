#include <stdio.h>

int main(void) {
  int hr24, hr12, minute;

  printf("Enter a 24-hour time: ");
  scanf("%2d : %2d", &hr24, &minute);

  hr12 = (hr24 == 0 || hr24 == 12) ? 12 : hr24 % 12;
  printf("Equivalent 12-hour time: %d:%2.2d", hr12 , minute);
  if (hr24 >= 12)
    printf(" PM\n");
  else
    printf(" AM\n");

  return 0;
}
