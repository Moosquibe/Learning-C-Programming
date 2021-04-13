#include <stdio.h>
#include <assert.h>

int *find_largest(int a[], int n) {
  int max_ind = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[max_ind])
      max_ind = i;
  }
  return &a[max_ind];
}

int main(void) {
  int a[5] = {3, 4, 1, 8, 5};

  assert(*find_largest(a, 5) == 8);
  return 0;
}
