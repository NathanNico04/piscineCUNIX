#include <stddef.h>

int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }

    int i = 0;

    while ((i + 1) * (i + 1) <= n)
    {
        i++;
    }

    return i;
}
