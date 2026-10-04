#include "my_calloc.h"

void *my_calloc(size_t n, size_t size)
{
    char *ptr = malloc(size * n);
    if (!ptr)
        return NULL;
    for (size_t i = 0; i < size * n; i++)
        ptr[i] = 0;
    return ptr;
}
