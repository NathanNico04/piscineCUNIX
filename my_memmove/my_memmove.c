#include "my_memmove.h"

#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (d == s || n == 0)
        return dest;

    if (d < s)
    {
        size_t i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        size_t i = n;
        while (i > 0)
        {
            i--;
            d[i] = s[i];
        }
    }

    return dest;
}
