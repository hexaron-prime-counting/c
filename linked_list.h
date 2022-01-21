#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdbool.h>


/*
 * struct linked_list - A single linked integer list.
 */
struct linked_list {
    struct node *head;
    struct node *tail;
};

/*
 * add - Add an element at the end of a linked_list.
 */
void add(struct linked_list *list, int element);

/*
 * any - Check if a condition f is satisfied by any element of a linked_list.
 *
 * A condition f is a function that takes an int element form the list as is first
 * input and an int param as is second input and returns a bool.
 */
bool any(struct linked_list *list, bool (*f)(int, int), int param);

void print(struct linked_list *list);

/*
 * free_elements - Free all elements of the linked_list.
 */
void free_elements(struct linked_list *list);

#endif /* _LINKED_LIST_H */
