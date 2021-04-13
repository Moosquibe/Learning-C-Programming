#include <stdio.h>

union {
    float float_view;
    struct {
      unsigned int fraction: 23;
      unsigned int exponent: 8;
      unsigned int sign: 1;
    } bf_view;
} float_num;

int main(void) {
  float_num.bf_view.sign = 1;
  float_num.bf_view.exponent = 128;
  float_num.bf_view.fraction = 0;

  printf("%f", float_num.float_view);
}