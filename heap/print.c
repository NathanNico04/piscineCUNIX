#include <stdio.h>

#include "heap.h"

static void print_rec(const struct heap *heap, size_t i, int *first)
{
    if (i >= heap->size)
        return;

    if (!*first)
        printf(" ");
    printf("%d", heap->array[i]);
    *first = 0;

    print_rec(heap, 2 * i + 1, first);
    print_rec(heap, 2 * i + 2, first);
}

void print_heap(const struct heap *heap)
{
    int first = 1;

    print_rec(heap, 0, &first);
    putchar('\n');
}
