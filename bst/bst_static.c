#include "bst_static.h"

#include <stddef.h>
#include <stdlib.h>

int size_t_to_int(size_t n)
{
    size_t i = 0;
    int convert = 0;
    while (i != n)
    {
        i++;
        convert++;
    }
    return convert;
}

void augm_capacity(struct bst *tree, size_t index)
{
    if (index < tree->capacity)
        return;

    size_t new_cap = tree->capacity;
    if (new_cap == 0)
        new_cap = 1;

    while (index >= new_cap)
        new_cap *= 2;

    struct value **new_data =
        realloc(tree->data, new_cap * sizeof(struct value *));
    if (!new_data)
        return;

    for (size_t i = tree->capacity; i < new_cap; i++)
        new_data[i] = NULL;

    tree->data = new_data;
    tree->capacity = new_cap;
}

struct bst *init(size_t capacity)
{
    struct bst *tree = malloc(sizeof(struct bst));
    if (!tree)
        return NULL;

    tree->data = calloc(capacity, sizeof(struct value *));
    if (!tree->data)
    {
        free(tree);
        return NULL;
    }

    tree->capacity = capacity;
    tree->size = 0;
    return tree;
}

void add(struct bst *tree, int value)
{
    if (!tree)
        return;

    struct value *v = malloc(sizeof(struct value));
    if (!v)
        return;
    v->val = value;

    size_t i = 0;
    while (1)
    {
        augm_capacity(tree, i);

        if (!tree->data[i])
        {
            tree->data[i] = v;
            tree->size++;
            break;
        }

        if (value < tree->data[i]->val)
            i = 2 * i + 1;
        else if (value > tree->data[i]->val)
            i = 2 * i + 2;
        else
        {
            free(v);
            break;
        }
    }
}

int search(struct bst *tree, int value)
{
    if (!tree)
        return -1;
    size_t i = 0;
    while (i < tree->capacity && tree->data[i] != NULL)
    {
        if (value == tree->data[i]->val)
            return size_t_to_int(i);

        if (value < tree->data[i]->val)
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    return -1;
}

void bst_free(struct bst *tree)
{
    if (!tree)
        return;

    for (size_t i = 0; i < tree->capacity; i++)
        free(tree->data[i]);

    free(tree->data);
    free(tree);
}
