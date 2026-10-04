#include <stddef.h>
#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;

    for (unsigned i = 0; i < n; i++)
    {
        unsigned spaces = n - 1 - i;
        unsigned stars = 2 * i + 1;

        for (unsigned s = 0; s < spaces; s++)
        {
            putchar(' ');
        }
        for (unsigned st = 0; st < stars; st++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    unsigned trunk_height = n / 2;
    for (unsigned t = 0; t < trunk_height; t++)
    {
        for (unsigned s = 0; s < n - 1; s++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }

    return 0;
}
