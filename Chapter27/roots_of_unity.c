#include <stdio.h>
#include <tgmath.h>
#include <complex.h>

#define PI 3.14159

int main(int argc, char* argv[]) {
    int n;
    complex double ur;

    printf("Give me a positive n: ");
    scanf(" %d", &n);

    printf("The n-th unit roots: \n");

    ur = cexp(2 * PI * I / n);
    for(int k = 0; k < n; k++) {
      printf("%g + %gi\n", creal(ur), cimag(ur));
      ur *= ur;
    }
    return 0;
}
