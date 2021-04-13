#include <stdio.h>

int main(void)
{
  float commission, rival_comission, value, num_share, share_price;

  printf("Enter number of shares traded: ");
  scanf("%f", &num_share);
  printf("Enther share price: ");
  scanf("%f", &share_price);

  value = num_share * share_price;

  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 500000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;

  if (commission < 39.00f)
    commission = 39.00f;

  if (num_share < 2000)
    rival_comission = 33.00f + .03f * num_share;
  else
    rival_comission = 33.00f + .02f * num_share;

  printf("Commission: $%.2f\n", commission);
  printf("Rival's comission: $%.2f\n", rival_comission);

  return 0;
}
