#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


bool is_even(int number) {
	return (number % 2 == 0);
};


int main() {
	struct linked_list *list = malloc(sizeof(struct linked_list));

	add(list, 3);

	if (any(list, is_even)) {
		printf("The list CONTAINS an even element.\n");
	} else {
		printf("The list contains NO even element.\n");
	}

	free_elements(list);
	free(list);
};
