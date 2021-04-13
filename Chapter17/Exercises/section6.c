#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int value;
    struct node *next;
};

void add_to_list(struct node **list, int n) {
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

void delete_from_list(struct node **list, int n) {
    struct node *cur, *prev;

    for (cur = *list, prev = NULL;
         cur != NULL && cur->value !=n;
         prev = cur, cur = cur->next)
         ;
    if (cur != NULL) {
        if (prev == NULL)
          *list = (*list)->next;
        else
          prev->next = cur->next;
        free(cur);
    }
}

int main(void) {
    struct node *list;

    add_to_list(&list, 2);
    add_to_list(&list, 3);
    add_to_list(&list, 4);

    delete_from_list(&list, 3);

    assert(list->value == 4);
    assert(list->next->value == 2);
    return 0;
}