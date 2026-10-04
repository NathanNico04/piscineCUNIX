#include <stddef.h>

void pointer_swap(int **a, int **b)
{
    int *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
