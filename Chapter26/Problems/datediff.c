#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct tm t1, t2;

    t1.tm_sec = t1.tm_min = t1.tm_hour = 0;
    t2.tm_sec = t2.tm_min = t2.tm_hour = 0;
    t1.tm_isdst = t2.tm_isdst = -1;

    printf("Date 1 - Year: ");
    scanf("%d", &t1.tm_year);

    printf("Date 1 - Month: ");
    scanf("%d", &t1.tm_mon);

    printf("Date 1 - Day: ");
    scanf("%d", &t1.tm_mday);

    printf("Date 2 - Year: ");
    scanf("%d", &t2.tm_year);

    printf("Date 2 - Month: ");
    scanf("%d", &t2.tm_mon);

    printf("Date 2 - Day: ");
    scanf("%d", &t2.tm_mday);

    printf("Difference is %d days.\n", abs((int) difftime(mktime(&t1), mktime(&t2)) / (60 * 60 * 24)));

    exit(EXIT_SUCCESS);
}