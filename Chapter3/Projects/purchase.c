#include <stdio.h>

int main(void) {
  int item_no, month, day, year;
  float unit_price;
  printf("Enter item number: ");
  scanf("%d", &item_no);
  printf("Enter unit price: ");
  scanf("%f", &unit_price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%2.2d/%2.2d/%d",
         item_no, unit_price, month, day, year);
  return 0;
}
