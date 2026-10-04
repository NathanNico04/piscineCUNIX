#include "insertion_sort.h"

static size_t array_len(void **array)
{
    size_t len = 0;

    while (array[len] != NULL)
        len++;
    return len;
}

void insertion_sort(void **array, f_cmp comp)
{
    size_t len = array_len(array);
    size_t i = 1;

    while (i < len)
    {
        void *key = array[i];
        size_t j = i;

        while (j > 0 && comp(array[j - 1], key) > 0)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        i++;
    }
}
