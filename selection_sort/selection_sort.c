#include <stddef.h>

void swap(int *a, int *b)
{
    if (!a || !b)
    {
        return;
    }

    int tmp = *a;
    *a = *b;
    *b = tmp;
}

size_t array_min(const int arr[], size_t start, size_t size)
{
    size_t min_index = start;

    for (size_t i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[min_index])
            min_index = i;
    }

    return min_index;
}

void selection_sort(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        size_t min_index = array_min(arr, i, size);

        if (i != min_index)
        {
            swap(&arr[i], &arr[min_index]);
        }
    }
}
