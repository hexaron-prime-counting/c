#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


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


/*
 * struct linked_list - A single linked integer list.
 */
struct linked_list {
    int length;
    struct node *head;
    struct node *tail;
};

/*
 * add - Add an element at the end of a linked_list.
 */
void add(struct linked_list *list, int element);

void print(const struct linked_list *list);

/*
 * free_elements - Free all elements of the linked_list.
 */
void free_elements(const struct linked_list *list);

#endif /* _LINKED_LIST_H */
