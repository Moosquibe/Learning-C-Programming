#include <stdio.h>
#include <time.h>

time_t first_midnight(int year) {
    struct tm datetime = {.tm_sec = 0,
                          .tm_min = 0,
                          .tm_hour = 0,
                          .tm_mday = 1,
                          .tm_mon = 0,
                          .tm_year = year - 1900};
    return (mktime(&datetime));
}

int main(int argc, char* argv[]) {
    time_t dt = first_midnight(1985);
    struct tm *bla = localtime(&dt);
    printf("%s", ctime(&dt));
    return 0;
}