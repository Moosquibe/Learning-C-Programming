#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

// Problem 3
struct complex {
  double real;
  double imaginary;
};

struct complex make_complex(double real, double imaginary) {
  return (struct complex) {.real = real, .imaginary = imaginary};
}

struct complex add_complex(struct complex a1, struct complex a2) {
  return (struct complex) {
    .real = a1.real + a2.real,
    .imaginary = a1.imaginary + a2.imaginary
  };
}

// Problem 4

typedef struct{
  double real;
  double imaginary;
} Complex;

Complex make_Complex(double real, double imaginary) {
  return (Complex) {.real = real, .imaginary = imaginary};
}

Complex add_Complex(Complex a1, Complex a2) {
  return (Complex) {
    .real = a1.real + a2.real,
    .imaginary = a1.imaginary + a2.imaginary
  };
}

// Problem 5
struct date {
  int month;
  int day;
  int year;
};

int day_of_year(struct date d) {
  const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int tot_days = d.day;

  for(int i=0; i < d.month - 1; i++)
    tot_days += days_in_month[i];

  if (d.year % 4 == 0 && d.month > 2)
    tot_days++;

  return tot_days;
}

int compare_dates(struct date d1, struct date d2) {
  int result;

  if (d1.year < d2.year)
    result = -1;
  else if (d1.year > d2.year)
    result = 1;
  else {
    if (d1.month < d2.month)
      result = -1;
    else if (d1.month > d2.month)
      result = 1;
    else {
      if (d1.day < d2.day)
        result = -1;
      else if (d1.day > d2.day)
        result = 1;
      else
        result = 0;
    }
  }
  return result;
}

// Problem 6

struct time {
  int hours, minutes, seconds;
};

struct time split_time(long total_seconds) {
  return (struct time) {
    .seconds = total_seconds % 60,
    .minutes = (total_seconds / 60) % 60,
    .hours = total_seconds / (60 * 60)
  };
}

// Problem 7
struct fraction {
  int numerator, denominator;
};

int gcd(int n, int m) {
  int rem;
  while (n % m != 0) {
    rem = n % m;
    n = m;
    m = rem;
  }
  return m;
}

struct fraction reduce(struct fraction f) {
  int cd = gcd(f.numerator, f.denominator);
  return (struct fraction) {
    .numerator = f.numerator / cd,
    .denominator = f.denominator /cd
  };
}

struct fraction add(struct fraction f1, struct fraction f2) {
  return reduce((struct fraction) {
      .numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator,
      .denominator = f1.denominator * f2.denominator
  });
}

struct fraction multiply(struct fraction f1, struct fraction f2) {
  return reduce((struct fraction) {
      .numerator = f1.numerator * f2.numerator,
      .denominator = f1.denominator * f2.denominator
  });
}

struct fraction divide(struct fraction f1, struct fraction f2) {
  return reduce((struct fraction) {
      .numerator = f1.numerator * f2.denominator,
      .denominator = f1.denominator * f2.numerator
  });
}

// Problem 8
struct color {
  int red;
  int green;
  int blue;
};

const struct color MAGENTA = {255, 0, 255};
const struct color MAGENTA2 = {.red = 255, .blue = 255};

// Problem 9
int min(int a, int b) {
  return (a < b) ? a : b;
}

int max(int a, int b) {
  return (a < b) ? b : a;
}

struct color make_color(int red, int green, int blue) {
  return (struct color) {
    .red = min(max(0, red), 255),
    .green = min(max(0, green), 255),
    .blue = min(max(0, blue), 255)
  };
}

int getRed(struct color c) {
  return c.red;
}

bool equal_color(struct color color1, struct color color2) {
  return color1.red == color2.red &&
         color1.green == color2.green &&
         color1.blue == color2.blue;
}

struct color brighter(struct color c) {
  if (equal_color(c, (struct color) {0, 0, 0}))
    return (struct color) {3, 3, 3};

  if (0 < c.red && c.red < 3)
    c.red = 3;
  if (0 < c.green && c.green < 3)
    c.green = 3;
  if (0 < c.blue && c.blue < 3)
    c.blue = 3;

  c.red = min(floor(c.red / 0.7), 255);
  c.green = min(floor(c.green / 0.7), 255);
  c.blue = min(floor(c.blue / 0.7), 255);
  return c;
}

struct color darker(struct color c) {
  return (struct color) {
    .red = floor(c.red * 0.7),
    .green = floor(c.green * 0.7),
    .blue = floor(c.blue * 0.7)
  };
}

int main(void) {
  struct complex c1, c2, c3;
  c1 = make_complex(1, 3);
  c2 = make_complex(-1, 2);
  c3 = add_complex(c1, c2);
  assert((c3.real == 0) && (c3.imaginary == 5));

  Complex d1, d2, d3;
  d1 = make_Complex(1, 3);
  d2 = make_Complex(1, -2);
  d3 = add_Complex(d1, d2);
  assert((d3.real == 2) && (d3.imaginary == 1));

  struct date date1 = (struct date) {3, 2, 2003};
  struct date date2 = (struct date) {3, 2, 2004};
  assert(day_of_year(date1) == 61);
  assert(day_of_year(date2) == 62);
  assert(compare_dates(date1, date2) == -1);
  assert(compare_dates(date2, date1) == 1);
  assert(compare_dates(date1, date1) == 0);

  struct time t = split_time(4000);
  assert(t.hours == 1 && t.minutes == 6 && t.seconds == 40);

  struct fraction f1 = {4, 6};
  struct fraction f2 = {2, 3};
  assert(reduce(f1).numerator == 2 && reduce(f1).denominator == 3);
  assert(add(f1, f2).numerator == 4 && add(f1, f2).denominator == 3);
  assert(multiply(f1, f2).numerator == 4 && multiply(f1, f2).denominator == 9);
  assert(divide(f1, f2).numerator == 1 && divide(f1, f2).denominator == 1);

  assert(MAGENTA.red == 255 && MAGENTA2.red == 255);
  assert(MAGENTA.blue == 255 && MAGENTA2.blue == 255);
  assert(MAGENTA.green == 0 && MAGENTA2.green == 0);
  return 0;
}


