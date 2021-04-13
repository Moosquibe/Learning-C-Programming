#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define PI 3.14

#define RECTANGLE 0
#define CIRCLE 1

struct point {
  int x, y;
};

struct shape {
  int shape_kind;
  struct point center;
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
};

double area(struct shape s) {
  double area;
  if (s.shape_kind == RECTANGLE) {
    area = s.u.rectangle.height * s.u.rectangle.width;
  } else if (s.shape_kind == CIRCLE) {
    area = 2 * PI * s.u.circle.radius;
  } else {
    printf("Unknown shape kind!");
    exit(EXIT_FAILURE);
  }
  return area;
}

struct shape move(struct shape s, int x, int y) {
  s.center.x += x;
  s.center.y += y;
  return s;
}

struct shape scale(struct shape s, double c) {
  if (s.shape_kind == RECTANGLE) {
    s.u.rectangle.height *= c;
    s.u.rectangle.width *= c;
  } else if (s.shape_kind == CIRCLE) {
    s.u.circle.radius *= c;
  } else {
    printf("Unknown shape kind");
    exit(EXIT_FAILURE);
  }

  return s;
} 

int main(void) {
  struct shape s;
  s.shape_kind = RECTANGLE;
  s.center.x = 2; s.center.y = 3;
  s.u.rectangle.width = 4;
  s.u.rectangle.height = 6;

  assert(area(s) == 24);
}



