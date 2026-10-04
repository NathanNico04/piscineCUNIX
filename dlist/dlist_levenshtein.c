#include <stdlib.h>

#include "dlist.h"

static unsigned int min3(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

static unsigned int compute_levenshtein_matrix(unsigned int **matrix,
                                               const struct dlist *list1,
                                               const struct dlist *list2)
{
    size_t len1 = list1->size;
    size_t len2 = list2->size;
    size_t i;
    size_t j;
    struct dlist_item *item1 = list1->head;

    for (i = 1; i <= len1; i++)
    {
        struct dlist_item *item2 = list2->head;
        for (j = 1; j <= len2; j++)
        {
            unsigned int cost = (item1->data == item2->data) ? 0 : 1;
            matrix[i][j] = min3(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1,
                                matrix[i - 1][j - 1] + cost);
            item2 = item2->next;
        }
        item1 = item1->next;
    }

    return matrix[len1][len2];
}

unsigned int dlist_levenshtein(const struct dlist *list1,
                               const struct dlist *list2)
{
    size_t len1 = list1->size;
    size_t len2 = list2->size;
    size_t i;
    size_t j;

    unsigned int **matrix = malloc((len1 + 1) * sizeof(unsigned int *));
    if (!matrix)
        return 0;

    for (i = 0; i <= len1; i++)
    {
        matrix[i] = malloc((len2 + 1) * sizeof(unsigned int));
        if (!matrix[i])
        {
            for (j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            return 0;
        }
    }

    for (i = 0; i <= len1; i++)
        matrix[i][0] = i;
    for (j = 0; j <= len2; j++)
        matrix[0][j] = j;

    unsigned int result = compute_levenshtein_matrix(matrix, list1, list2);

    for (i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);

    return result;
}
