#include "array_vice_max.h"

#include <stddef.h>
int array_vice_max(const int vec[], size_t size)
{
    if (size < 2 || !vec)
        return 0;

    int max = vec[0];
    int max_seconds = vec[1];

    if (max_seconds > max)
    {
        int tmp = max;
        max = max_seconds;
        max_seconds = tmp;
    }

    for (size_t i = 2; i < size; i++)
    {
        if (vec[i] > max)
        {
            max_seconds = max;
            max = vec[i];
        }
        else if (vec[i] > max_seconds && vec[i] < max)
        {
            max_seconds = vec[i];
        }
    }
    return max_seconds;
}
