

#include <limits.h>
#include <stddef.h>

int array_max(const int array[], size_t size)
{
    if (size == 0)
    {
        return INT_MIN;
    }
    int max = array[0];
    size_t i = 1;
    while (i != size)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        i++;
    }
    return max;
}
