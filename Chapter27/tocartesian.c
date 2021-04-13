#include <stdio.h>
#include <tgmath.h>

int main(int argc, char* argv[]) {
    double a, b;
    double r, fi;

    printf("Give me the radius: ");
    scanf(" %lf", &r);
    printf("Give me the angle: ");
    scanf(" %lf", &fi);

    a = r * cos(fi);
    b = r * sin(fi);

    printf("a: %lf,  b: %lf\n", a, b);
    return 0;
}