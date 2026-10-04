#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    int *low = begin;
    int *high = end;

    while (low < high)
    {
        int *mid = low + (high - low) / 2;

        if (*mid < elt)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}
