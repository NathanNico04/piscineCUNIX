#include "array_max_min.h"

void array_max_min(int tab[], size_t size, int *max, int *min)
{
    if (size == 0 || !tab)
        return;
    *max = tab[0];
    *min = tab[0];
    size_t i = 1;
    while (i < size)
    {
        if (tab[i] > *max)
        {
            *max = tab[i];
        }
        if (tab[i] < *min)
        {
            *min = tab[i];
        }
        i++;
    }
}
