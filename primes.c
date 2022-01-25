#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


int main() {
	const int upper_bound = 100000000;
	struct linked_list *primes = malloc(sizeof(struct linked_list));
	add(primes, 2);
	int count = 1;

	for (int p = 3; p < upper_bound; p += 2) {
		/* iterate over the nodes */
		struct node *node = primes->head;

		while (node != NULL) {
			const int q = node->element;

			if (q * q > p) {
				count++;
				add(primes, p);
				break;
			}

			if (p % q == 0) {
				break;
			}

			node = node->next;
		}
	}

	printf("Found %d primes below %d\n", count, upper_bound);
	// print(primes);

	free_elements(primes);
	free(primes);
}
