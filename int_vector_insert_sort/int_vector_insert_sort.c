#include "int_vector_insert_sort.h"

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    if (vec.size <= 1)
        return vec;

    for (size_t i = 1; i < vec.size; i++)
    {
        size_t j = i;
        while (j > 0 && vec.data[j] < vec.data[j - 1])
        {
            vec = swap(vec, j, j - 1);
            j--;
        }
    }
    return vec;
}
