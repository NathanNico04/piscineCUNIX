#include <assert.h>
#include <stdlib.h>

#include "heap.h"

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);

    int root = heap->array[0];

    heap->size--;
    heap->array[0] = heap->array[heap->size];

    size_t i = 0;

    while (1)
    {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        size_t largest = i;

        if (left < heap->size && heap->array[left] > heap->array[largest])
            largest = left;
        if (right < heap->size && heap->array[right] > heap->array[largest])
            largest = right;
        if (largest == i)
            break;

        swap(&heap->array[i], &heap->array[largest]);
        i = largest;
    }

    if (heap->size < heap->capacity / 2 && heap->capacity > 8)
    {
        heap->capacity /= 2;
        if (heap->capacity < 8)
            heap->capacity = 8;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }

    return root;
}
