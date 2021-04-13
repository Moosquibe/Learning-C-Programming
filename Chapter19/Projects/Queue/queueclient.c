#include <stdio.h>
#include "queueADT.h"

int main (void) {
    Queue q1 = create();
    Queue q2 = create();

    insert(3, q1);
    insert(4, q1);
    insert(5, q1);
    rem(q1);

    printf("%d is at the front of q1\n", first(q1));
    printf("%d is at the back of q1\n", last(q1));

    if (is_empty(q2)) {
        printf("q2 is empty\n");
    } else {
        printf("q2 is not empty\n");
    }

    destroy(q2);
    destroy(q1);
}