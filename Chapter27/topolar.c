#include <stdio.h>
#include <tgmath.h>

int main(int argc, char* argv[]) {
    double a, b;
    double r, fi;

    printf("Give me the real part: ");
    scanf(" %lf", &a);
    printf("Give me the imaginary part: ");
    scanf(" %lf", &b);

    r = sqrt(a * a + b * b);
    fi = fmod(atan(b/a), 2 * 3.14);

    printf("Radius: %lf,  Angle: %lf\n", r, fi);

    return 0;
}