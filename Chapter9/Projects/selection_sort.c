#include <stdio.h>
#include <assert.h>

#define LENGTH 5

void selection_sort(int a[], int n) {
  int argmax = 0;
  int tmp;

  if (n == 1)
    return;

  for (int i = 0; i < n; i++) {
    if (a[i] > a[argmax])
      argmax = i;
  }

  tmp = a[n-1];
  a[n-1] = a[argmax];
  a[argmax] = tmp;

  selection_sort(a, n-1);
}

int main(void) {
  int a[LENGTH];
  printf("Enter a list of %d integers: ", LENGTH);
  for(int i = 0; i < LENGTH; i++) {
    scanf(" %d", &a[i]);
  }

  selection_sort(a, LENGTH);

  printf("Sorted array: ");
  for(int i = 0; i < LENGTH; i++)
    printf("%d ", a[i]);

  printf("\n");

  return 0;
}
