#include <stdio.h>
#include <assert.h>

int check(int x, int y, int n) {
  // Returns 1 if both x an y are between 0 and n-1
  // inclusive and zero otheriwse.
  if (x < 0 || y < 0 || x >= n || y >= n)
    return 0;
  else
    return 1;
}

int gcd(int m, int n) {
  // Computes the greatest common divisor of m and
  // n using the Euclidean algorithm
  int r;

  while (m % n != 0) {
    r = m % n;
    m = n; n = r;
  }

  return r;
}

int day_of_year(int month, int day, int year) {
  // Returns the day of the year (an integer between
  // 1 and 366) specified by the three arguments.

  int days = day;

  for(int i = 1; i < month; i++) {
    switch(i) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        days += 31;
        break;
      case 4: case 6: case 9: case 11:
        days += 30;
        break;
      case 2:
        days += 28;
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
          days += 1;
        break;
    }
  }
  return days;
}

int num_digits(int n) {
  // Returns the number of digits in n
  if (n == 0)
    return 0;

  int digits = 0;
  while (n != 0) {
    n /= 10;
    digits++;
  }
  return digits;
}

int digit(int n, int k) {
  // Returns the kth digit of n (from the right)
  // or zero if k > n
  for(int i=0; i < k - 1; i++) {
    n /= 10;
  }

  return n % 10;
}


int main(void) {
  int x, y, z;

  // Test check
  x = check(2, 3, 3);
  y = check(2, 3, 4);
  assert(x == 0);
  assert(y == 1);

  // Test gcd
  x = gcd(11, 13);
  y = gcd(4, 8);
  z = gcd(8, 4);
  assert(x == 1);
  assert(y == 4);
  assert(z == 4);

  // Test day_of_year
  x = day_of_year(12, 3, 2012);
  y = day_of_year(1, 5, 2015);
  assert(x == 338);
  assert(y == 5);

  // Test num_digits
  x = num_digits(0);
  y = num_digits(342);
  z = num_digits(7);
  assert(x == 0);
  assert(y == 3);
  assert(z == 1);

  // Test digit
  x = digit(234, 2);
  y = digit(1312, 1);
  z = digit(34, 3);
  assert(x == 3);
  assert(y == 2);
  assert(z == 0);

  return 0;
}
