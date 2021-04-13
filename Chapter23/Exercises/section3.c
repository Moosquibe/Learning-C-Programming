#include <stdio.h>
#include <assert.h>
#include <math.h>

float round_nearest(float x, int digits) {
  x *= powf(10, digits);
  x = nearbyintf(x);
  return x / powf(10, digits);
}

int main(int argc, char* argv[]) {
  assert(round_nearest(3.14159, 3) == 3.142F);
}

