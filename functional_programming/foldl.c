#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    int acc = 0;
    size_t i = 0;

    while (i < len)
    {
        acc = func(acc, array[i]);
        i++;
    }
    return acc;
}
