#include <stdio.h>
#include <assert.h>

void swap(int *p, int *q) {
  *p = *p + *q;
  *q = *p - *q;
  *p = *p - *q;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
  *sec = total_sec % 60;
  *min = (total_sec % 3600) / 60;
  *hr = total_sec / 3600;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  if (a[1] < a [2]) {
    *largest = a[2];
    *second_largest = a[1];
  } else {
    *largest = a[1];
    *second_largest = a[2];
  }

  if (n > 2) {
    for (int i = 3; i < n; i++) {
      if (a[i] > *largest) {
        *second_largest = *largest;
        *largest = a[i];
      } else if (a[i] > *second_largest) {
        *second_largest = a[i];
      }
    }
  }
}

void split_date(int day_of_year, int year, int *month, int *day) {
  // Encode month lengths
  int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 4 == 0)
    month_days[1] = 29;

  *month = 1;
  for (int i = 0; i < 12; i++) {
    if (day_of_year <= month_days[i]) {
      *day = day_of_year;
      break;
    }
    else {
      day_of_year -= month_days[i];
      (*month)++;
    }
  }
}

int main(void) {
  int a = 5, b = 3;
  swap(&a, &b);
  assert(a == 3 && b == 5);

  long total_sec = 9 * 60 * 60 + 35 * 60 + 40;
  int hr, min, sec;
  split_time(total_sec, &hr, &min, &sec);
  assert(hr == 9 && min == 35 && sec == 40);

  int c[7] = {3, 5, 2, 2, 7, 8, 6};
  int largest, second_largest;
  find_two_largest(c, 7, &largest, &second_largest);
  assert(largest == 8 && second_largest == 7);

  int d[7] = {3, 5, 2, 2, 8, 8, 6};
  find_two_largest(d, 7, &largest, &second_largest);
  assert(largest == 8 && second_largest == 8);

  int month, day;
  split_date(63, 2005, &month, &day);
  assert(month == 3 && day == 4);

  return 0;
}
l
