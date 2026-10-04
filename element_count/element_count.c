#include <stddef.h>

size_t element_count(int *begin, int *end)
{
    size_t count = 0;
    while (begin < end)
    {
        count++;
        begin++;
    }

    return count;
}
