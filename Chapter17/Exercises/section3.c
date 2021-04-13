#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value) {
    int *array = malloc(n * sizeof(int));
    if (array) {
      for(int i = 0; i < n; i++)
        array[i] = initial_value;
    }
    return array;
}

int main(void) {
    int *p = create_array(10, 3);
    return 0;
}