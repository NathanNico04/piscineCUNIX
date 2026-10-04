#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int acc = 0;
    size_t i = len;

    while (i > 0)
    {
        i--;
        acc = func(array[i], acc);
    }
    return acc;
}
