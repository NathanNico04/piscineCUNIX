#include <stddef.h>

unsigned long factorial(unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
