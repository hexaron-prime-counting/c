#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"


bool divides_below_sqrt(int prime, int number) {
	return (prime * prime <= number && number % prime == 0);
};


void print(int number, char* message) {
	printf("%d: %s\n", number, message);
}


int main() {
	const int upper_bound = 100000;
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

	printf("%d\n", count);

	free_elements(primes);
	free(primes);
};
