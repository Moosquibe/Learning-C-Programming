#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int sum_array(const int a[], int n) {
  int sum = 0;
  int *p;

  for(p = a; p < a + n; p++) {
    sum += *p;
  }
  return sum;
}

bool search(const int a[], int n, int key) {
  int *p;

  for (p = a; p < a + n; p++) {
    if (*p == key)
      return true;
  }
  return false;
}

void store_zeros(int a[], int n) {
  int *p;

  for(p = a; p < a + n; p++)
    *p = 0;
}

double inner_product(const double *a, const double *b, int n) {
  double *p = a, *q = b, sum = 0;
  while (p < a + n && q < b + n) {
    sum += *p * *q;
    p++; q++;
  }
  return sum;
}

int *find_middle(const int *a, int n) {
  return a + n/2;
}

void find_largest(const int *a, int n, int *largest) {
  int *p;
  *largest = *a;
  for (p = a + 1; p < a + n; p++) {
    if (*p > *largest)
      *largest = *p;
  }
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
  int *p;

  if (*a > *(a+1)) {
    *largest = *a;
    *second_largest = *(a+1);
  } else {
    *largest = *(a + 1);
    *second_largest = *a;
  }

  for(p = a + 2; p < a + n; p++) {
    if (*p > *largest) {
      *second_largest = *largest;
      *largest = *p;
    } else if (*p > *second_largest) {
      *second_largest = *p;
    }
  }
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};

  assert(sum_array(a, 5) == 15);
  assert(search(a, 5, 3) == true);
  assert(search(a, 5, 8) == false);

  store_zeros(a, 5);
  assert(sum_array(a,5) == 0);


  double b[5] = {1, 2, 3, 4, 5};
  double c[5] = {5, 4, 3, 2, 1};

  assert(inner_product(b, c, 5) == 35);

  int d[5] = {1, 2, 3, 4, 5};

  assert(find_middle(d, 5) == &d[2]);

  int largest, second_largest;
  find_largest(d, 5, &largest);
  assert(largest == 5);

  find_two_largest(d, 5, &largest, &second_largest);
  assert(largest == 5 && second_largest == 4);

  return 0;
}
