#include "bubble_sort.h"

void bubble_sort(int array[], size_t size)
{
    size_t i = 0;

    while (i < size)
    {
        size_t j = 0;

        while (j < size - 1)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}
