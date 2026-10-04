#include <stdio.h>

static void hanoi_rec(unsigned n, unsigned from, unsigned to, unsigned aux)
{
    if (n == 0)
        return;
    hanoi_rec(n - 1, from, aux, to);
    printf("%u->%u\n", from, to);
    hanoi_rec(n - 1, aux, to, from);
}

void hanoi(unsigned n)
{
    hanoi_rec(n, 1, 3, 2);
}
