#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


int main() {
	const int upper_bound = 100000000;
	struct linked_list *primes = malloc(sizeof(struct linked_list));
	int count = 0;

	for (int p = 2; p < upper_bound; p++) {
		/* check if p is prime */
		bool is_prime = true;

		/* iterate over the nodes */
		struct node *node = primes->head;

		while (node != NULL) {
			const int q = node->element;

			if (q * q > p) {
				break;
			}

			if (p % q == 0) {
				is_prime = false;
				break;
			}

			node = node->next;
		}

		if (is_prime) {
			count++;
			add(primes, p);
		}
	}

	printf("Found %d primes below %d\n", count, upper_bound);

	free_elements(primes);
	free(primes);
}
