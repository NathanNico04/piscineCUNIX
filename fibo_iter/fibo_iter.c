#include <stddef.h>

unsigned long fibo_iter(unsigned long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    unsigned long a = 0;
    unsigned long b = 1;
    unsigned long i;
    unsigned long res = 0;

    for (i = 2; i <= n; i++)
    {
        res = a + b;
        a = b;
        b = res;
    }

    return res;
}
