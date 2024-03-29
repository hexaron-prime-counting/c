#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"


void add(struct linked_list *list, int element) {
    struct node *node = malloc(sizeof(struct node));

    /* write data into new node */
    node->element = element;

    struct node *tail = list->tail;

    if (tail == NULL) {
        /* initialize the length and the head and tail node of list */
        list->length = 1;
        list->head = node;
        list->tail = node;
    } else {
        /* update the length and the next node of tail and the tail node of list */
        list->length++;
        tail->next = node;
        list->tail = node;
    }
}

void print(const struct linked_list *list) {
    printf("[");

    for (struct node *node = list->head; 1; node = node->next) {
        if (node->next != NULL) {
            printf("%d, ", node->element);
        } else {
            printf("%d", node->element);
            break;
        }
    }

    printf("]\n");
}

void free_elements(const struct linked_list *list) {
    struct node *node = list->head;
    struct node *next_node = NULL;

    while (node != NULL) {
        next_node = node->next;
        free(node);
        node = next_node;
    }
}
