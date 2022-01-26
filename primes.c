#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


int main() {
	const int upper_bound = 100000000;
	struct linked_list *primes = malloc(sizeof(struct linked_list));

	add(primes, 2);

	for (int p = 3; p < upper_bound; p += 2) {
		for (struct node *node = primes->head; node != NULL; node = node->next) {
			const int q = node->element;

			if (q * q > p) {
				add(primes, p);
				break;
			}

			if (p % q == 0) {
				break;
			}
		}
	}

	printf("Found %d primes below %d\n", primes->length, upper_bound);

	free_elements(primes);
	free(primes);
}
