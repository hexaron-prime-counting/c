#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


bool divides_below_sqrt(int prime, int number) {
	return (prime * prime <= number && number % prime == 0);
}


int main() {
	const int upper_bound = 20;
	struct linked_list *primes = malloc(sizeof(struct linked_list));
	int count = 0;

	for (int p = 2; p < upper_bound; p++) {
		/* check if p is prime */
		bool is_prime = true;

		if (any(primes, divides_below_sqrt, p)) {
			is_prime = false;
		}

		if (is_prime) {
			count++;
			add(primes, p);
		}
	}

	printf("Found %d primes below %d:\n", count, upper_bound);

	print(primes);

	free_elements(primes);
	free(primes);
}
