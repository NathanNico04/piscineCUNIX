#include "functional_programming.h"
#include "functional_programming_advanced.h"

static int max_func(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int max(int *array, size_t len)
{
    if (len == 0)
        return 0;
    return foldl(array, len, max_func, 0);
}
