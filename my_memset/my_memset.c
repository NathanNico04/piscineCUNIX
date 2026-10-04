#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;
    unsigned char value = c;
    size_t i = 0;

    while (i < n)
    {
        ptr[i] = value;
        i++;
    }
    return s;
}
