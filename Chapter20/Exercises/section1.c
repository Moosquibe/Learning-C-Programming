#include <stdio.h>
#include <assert.h>

#define MK_COLOR(r,g,b) ((long) ((b) << 16 | (g) << 8 | (r)))
#define GET_RED(c) ((c) & 0xFF)
#define GET_GREEN(c) (((c) >> 8) & 0xFF)
#define GET_BLUE(c) (((c) >> 16) & 0xFF)

unsigned short swap_bytes(unsigned short i) {
  unsigned short byte2 = i & 0xFF;
  unsigned short byte1 = (i >> 8) & 0xFF;
  
  return (byte2 << 8) | byte1;
}
unsigned short swap_bytes2(unsigned short i) {
  return (i << 8) | (i >> 8);
}
unsigned int rotate_left(unsigned int i, int n) {
  return (i << n) | (i >> (sizeof(unsigned int) * 8 - n));
}
unsigned int rotate_right(unsigned int i, int n) {
  return (i >> n) | (i << (sizeof(unsigned int) * 8 -n));
}
int count_ones(unsigned char ch) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        count += ch & 0x1;
        ch = ch >> 1;
    }
    return count;
}

int count_ones_rec(unsigned char ch) {
    int count;
    if (ch == 0)
      return 0;

    if (ch & 0x1)
      count = 1 + count_ones_rec(ch >> 1);
    else
      count = count_ones_rec(ch >> 1);

    return count;
}

unsigned int reverse_bits(unsigned int n) {
   unsigned int reversed = 0;
   while (n) {
       reversed = (reversed << 1) | (n & 0x1);
       n = n >> 1;
   }
   return reversed;
}

int main(void) {
    unsigned long color = MK_COLOR(174, 167, 89);
    unsigned short i;

    assert(GET_RED(color) == 174);
    assert(GET_GREEN(color) == 167);
    assert(GET_BLUE(color) == 89);

    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &i);
    printf("Number with bytes swapped: %hx\n", swap_bytes(i));

    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_right(0x12345678, 4) == 0x81234567);
   
    assert(count_ones(0xF) == 4);
    assert(count_ones_rec(0xFF) == 8);

    assert(reverse_bits(0xFA) == 0x5F);
}