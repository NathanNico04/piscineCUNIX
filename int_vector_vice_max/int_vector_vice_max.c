#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int second = vec.data[1];

    if (second > max)
    {
        int tmp = max;
        max = second;
        second = tmp;
    }

    size_t i = 2;

    while (i < vec.size)
    {
        if (vec.data[i] > max)
        {
            second = max;
            max = vec.data[i];
        }
        else if (vec.data[i] > second)
        {
            second = vec.data[i];
        }
        i++;
    }

    return second;
}
