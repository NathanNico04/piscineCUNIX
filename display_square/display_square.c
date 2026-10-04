#include <stddef.h>
#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;
    if (width % 2 == 0)
        width++;

    int ligne = (width + 1) / 2;

    for (int i = 0; i < width; i++)
    {
        putchar('*');
    }
    putchar('\n');

    for (int j = 1; j < ligne - 1; j++)
    {
        putchar('*');
        for (int z = 1; z < width - 1; z++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    if (ligne > 1)
    {
        for (int i = 0; i < width; i++)
            putchar('*');
        putchar('\n');
    }
}
