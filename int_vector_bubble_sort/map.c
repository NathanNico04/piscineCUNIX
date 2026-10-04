#include <stdlib.h>

#include "functional_programming.h"

int *map(int *array, size_t len, int (*func)(int))
{
    int *res = malloc(len * sizeof(int));
    if (!res && len > 0)
        return NULL;
    for (size_t i = 0; i < len; i++)
    {
        res[i] = func(array[i]);
    }
    return res;
}
