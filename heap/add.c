#include <stdlib.h>

#include "heap.h"

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }

    heap->array[heap->size] = val;
    size_t i = heap->size;

    heap->size++;

    while (i > 0)
    {
        size_t parent = (i - 1) / 2;

        if (heap->array[parent] >= heap->array[i])
            break;

        swap(&heap->array[parent], &heap->array[i]);
        i = parent;
    }
}
