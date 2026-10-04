#include <stddef.h>
#include <stdio.h>

int main(void)
{
    char c;

    for (c = 'a'; c <= 'z'; c++)
    {
        putchar(c);
        if (c != 'z')
            putchar(' ');
    }
    putchar('\n');
    return 0;
}
