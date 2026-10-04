#include <stdbool.h>
#include <stdio.h>

#include "functional_programming.h"
#include "functional_programming_advanced.h"

static bool is_even(int n)
{
    return n % 2 == 0;
}

static int print_elem(int n)
{
    printf("%d\n", n);
    return n;
}

void print_even(int *array, size_t len)
{
    int *filtered = NULL;
    size_t flen = filter(array, len, &filtered, is_even);
    if (flen > 0)
    {
        int *mapped = map(filtered, flen, print_elem);
        free(mapped);
    }
    free(filtered);
}
