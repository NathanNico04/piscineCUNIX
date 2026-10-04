#include <stddef.h>

int my_pow(int a, unsigned long b)
{
    int res = 1;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = res * a;
        }

        a = a * a;
        b = b / 2;
    }

    return res;
}
