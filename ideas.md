# Problem: The code is extremely slow

## Possible cause

`malloc()` gets called whenever a new `node` is created, which happens for every new prime.

## Possible fix

Make a node not contain a single element but an array of elements.
Its struct then becomes:
```C
struct node {
    int *elements;
    int size;
    struct node *next;
};
```

Now when creating a node we also have to allocate memory as follows:
```C
size = 2 * previous_node->size; /* calculate size as next power of two */

struct node *node = malloc(sizeof(struct node));
node->size = size;
node->elements = calloc(size, sizeof(int));
```

## Discussion

`linked_list` starts out empty.
On the first `add()` it will create a node of size `1`.
On the next `add()` it will create a node of size `2`, making the `linked_list` effectively now use `3 * sizeof(inf)` of memory.

If `m` elements have been added, the number of nodes is:
$$
n = ceil(log_2(m + 1)).
$$

Therefore the allocated memory is
$$
2^m - 1.
$$

This shows that for `m` elements we allocate at least `m` and at most `2 * m - 1` memory:

- The worst cases are exactly at $m = 2^k$ where we have $2^k - 1$ elements too many.
- The best cases are exactly at $m = 2^k - 1$ where we have no elements too many.
