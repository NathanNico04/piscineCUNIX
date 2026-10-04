#include "lca.h"

static int find_index(int *values, int length, int val)
{
    int i = 0;
    while (i < length)
    {
        if (values[i] == val)
            return i;
        i++;
    }
    return -1;
}

int lca(int *values, int length, int p, int q)
{
    int ip = find_index(values, length, p);
    int iq = find_index(values, length, q);

    while (ip != iq)
    {
        if (ip > iq)
            ip = (ip - 1) / 2;
        else
            iq = (iq - 1) / 2;
    }

    return values[ip];
}
