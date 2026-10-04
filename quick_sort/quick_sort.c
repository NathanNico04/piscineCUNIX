#include <stddef.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static size_t partition(int *tab, size_t low, size_t high)
{
    int pivot = tab[high];
    size_t i = low;
    size_t j = low;

    while (j < high)
    {
        if (tab[j] <= pivot)
        {
            swap(&tab[i], &tab[j]);
            i++;
        }
        j++;
    }
    swap(&tab[i], &tab[high]);
    return i;
}

static void quicksort_rec(int *tab, size_t low, size_t high)
{
    if (low >= high)
        return;

    size_t p = partition(tab, low, high);

    if (p > low)
        quicksort_rec(tab, low, p - 1);
    quicksort_rec(tab, p + 1, high);
}

void quicksort(int *tab, size_t len)
{
    if (tab == NULL || len < 2)
        return;

    quicksort_rec(tab, 0, len - 1);
}
