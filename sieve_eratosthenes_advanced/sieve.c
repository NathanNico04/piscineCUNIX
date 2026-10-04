#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;

    char *marked = calloc(n, sizeof(char));
    if (!marked)
        return;

    int compteur = 0;
    int i = 2;

    while (i < n)
    {
        if (marked[i] == 0)
            compteur++;

        int multiple = i * 2;
        while (multiple < n)
        {
            marked[multiple] = 1;
            multiple += i;
        }
        i++;
    }

    printf("%d\n", compteur);
    free(marked);
}
