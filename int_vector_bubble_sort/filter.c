#include <stdbool.h>
#include <stdlib.h>

#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    size_t count = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (func(array[i]))
            count++;
    }
    *out_array = malloc(count * sizeof(int));
    if (!*out_array && count > 0)
        return 0;
    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (func(array[i]))
        {
            (*out_array)[j] = array[i];
            j++;
        }
    }
    return count;
}
