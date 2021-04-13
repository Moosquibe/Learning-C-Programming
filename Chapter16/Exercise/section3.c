#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

struct point {
  int x,y;
};

struct rectangle{
  struct point upper_left, lower_right;
};

double area(struct rectangle r){
  double a = r.upper_left.y - r.lower_right.y;
  double b = r.lower_right.x - r.upper_left.x;
  return a*b;
}

struct point center(struct rectangle r) {
  return (struct point) {
    .x = floor((r.upper_left.x + r.lower_right.x) / 2),
    .y = floor((r.upper_left.y + r.lower_right.y) / 2)
  };
}

struct point translate(struct point p, int x, int y) {
  return (struct point) {
    .x = p.x + x,
    .y = p.y + y
  };
}

bool in_rectangle(struct point p, struct rectangle r) {
  return p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
         p.y >= r.lower_right.y && p.y <= r.upper_left.y;
}


int main(void) {
  struct rectangle r = {
    .upper_left = (struct point) {1, 3},
    .lower_right = (struct point) {3, 1}
  };
  struct point p = {0, 2};

  assert(area(r) == 4);
  assert(center(r).x == 2 && center(r).y == 2);
  assert(!in_rectangle(p, r));
  p = translate(p, 2, 0);
  assert(in_rectangle(p, r));
}
