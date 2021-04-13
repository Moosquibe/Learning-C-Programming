#include <stdio.h>

int main() {
  float wind_speed;

  printf("Enter the wind speed (in knots): ");
  scanf("%f", &wind_speed);

  if (wind_speed < 1) 
    printf("Description: Calm\n");
  else if (wind_speed < 4)
    printf("Description: Light Air\n");
  else if (wind_speed < 28)
    printf("Description: Breeze\n");
  else if (wind_speed < 48)
    printf("Description: Gale\n");
  else if (wind_speed <= 63)
    printf("Description: Storm\n");
  else
    printf("Description: Hurricane\n");

  return 0;
}
