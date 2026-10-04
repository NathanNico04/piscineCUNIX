#include "int_vector_bubble_sort.h"

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    if (vec.size <= 1)
        return vec;

    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (size_t i = 0; i < vec.size - 1; i++)
        {
            if (vec.data[i] > vec.data[i + 1])
            {
                vec = swap(vec, i, i + 1);
                swapped = 1;
            }
        }
    }
    return vec;
}
