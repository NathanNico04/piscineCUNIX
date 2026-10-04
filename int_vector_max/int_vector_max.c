#include "int_vector_max.h"

int int_vector_max(const struct int_vector vec)
{
    int max = vec.data[0];
    size_t i = 1;

    while (i < vec.size)
    {
        if (vec.data[i] > max)
            max = vec.data[i];
        i++;
    }

    return max;
}
