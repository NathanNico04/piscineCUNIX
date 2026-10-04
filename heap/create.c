#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *heap = malloc(sizeof(struct heap));

    if (heap == NULL)
        return NULL;

    heap->array = malloc(sizeof(int) * 8);
    if (heap->array == NULL)
    {
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->capacity = 8;

    return heap;
}
