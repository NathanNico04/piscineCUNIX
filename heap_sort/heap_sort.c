#include "heap_sort.h"

#include <stddef.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void sift_down(int *array, size_t size, size_t i)
{
    while (1)
    {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        size_t largest = i;

        if (left < size && array[left] > array[largest])
            largest = left;
        if (right < size && array[right] > array[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&array[i], &array[largest]);
        i = largest;
    }
}

void heapify(int *array, size_t size)
{
    if (size < 2)
        return;
    for (size_t i = (size - 2) / 2 + 1; i > 0; i--)
    {
        sift_down(array, size, i - 1);
    }
}

void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;
    heapify(array, size);
    for (size_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        sift_down(array, i, 0);
    }
}
