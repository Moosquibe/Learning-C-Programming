#include <stdio.h>

#define PI 3.14f

int main(void) {
  float radius = 10.0f;
  printf("The volume of the sphere of radius %.2fm is %.2fm^3\n", radius, 4.0f/3.0f * PI * radius * radius * radius);
  return 0;
}
