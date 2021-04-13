#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include "queue.h"

int main(void) {
    // Test stack
    push(3);
    push(5);
    assert(pop() == 5);

    // Test queue
    insert(3);
    //insert(2);
    //insert(1);
    //rem();

    //assert(first() == 2);
    //assert(last() == 1);

    return 0;
}