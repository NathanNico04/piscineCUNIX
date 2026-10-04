#include "hill_array.h"

#include <stddef.h>

int top_of_the_hill(int tab[], size_t len)
{
    size_t i;
    size_t top_start;

    if (len == 0)
        return -1;

    i = 0;
    while (i < len - 1 && tab[i] <= tab[i + 1])
    {
        if (tab[i] < 0)
            return -1;
        i++;
    }

    if (i < len && tab[i] < 0)
        return -1;

    if (i == len - 1)
    {
        if (tab[len - 1] < 0)
            return -1;

        top_start = i;
        while (top_start > 0 && tab[top_start - 1] == tab[i])
            top_start--;

        return top_start;
    }

    top_start = i;
    while (top_start > 0 && tab[top_start - 1] == tab[i])
        top_start--;

    while (i < len - 1)
    {
        if (tab[i] < 0)
            return -1;
        if (tab[i] < tab[i + 1])
            return -1;
        i++;
    }

    if (tab[len - 1] < 0)
        return -1;

    return top_start;
}
