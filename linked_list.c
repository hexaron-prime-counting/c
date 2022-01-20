#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


/*
 * struct node - Node to be chained in a linked_list.
 *
 * @element - the element stored in this node
 * @next - the next node in the linked_list
 */
struct node {
    int element;
    struct node *next;
};


void add(struct linked_list *list, int element) {
    struct node *node = malloc(sizeof(struct node));

    /* write data into new node */
    node->element = element;

    struct node *tail = list->tail;

    if (tail == NULL) {
        /* initialize the head and tail node of list */
        list->head = node;
        list->tail = node;
    } else {
        /* update the next node of tail and the tail node of list */
        tail->next = node;
        list->tail = node;
    }
};

bool any(struct linked_list *list, bool (*f)(int)) {
    struct node *node = list->head;

    while (node != NULL) {
        if ((*f)(node->element)) {
            return true;
        }

        node = node->next;
    }

    return false;
};

void free_elements(struct linked_list *list) {
    struct node *node = list->head;
    struct node *next_node = NULL;

    while (node != NULL) {
        next_node = node->next;
        free(node);
        node = next_node;
    }
};
