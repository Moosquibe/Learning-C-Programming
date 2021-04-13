#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int month, day, year;
    const char* MONTHS[12] = {"January", "February", "March", "April", 
                              "May", "June", "July", "August", "September", 
                              "October", "November", "December"};

    if (argc != 2) {
        fprintf(stderr, "Usage: date <%%m-%%d-%%Y> or <%%m/%%d/%%Y>\n");
        exit(EXIT_FAILURE);
    }

    if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) != 3 || 
        sscanf(argv[1], "%d/%d/%d", &month, &day, &year) != 3) {
            fprintf(stderr, "Dat is not in one of the specified formats");
    }

    printf("%s %d, %d\n", MONTHS[month-1], day, year);
    return 0;
}