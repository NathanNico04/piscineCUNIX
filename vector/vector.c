#include "vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *v = malloc(sizeof(struct vector));
    if (!v)
        return NULL;
    v->data = malloc(n * sizeof(int));
    if (!v->data)
    {
        free(v);
        return NULL;
    }
    v->size = 0;
    v->capacity = n;
    return v;
}

void vector_destroy(struct vector *v)
{
    if (!v)
        return;
    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (!v)
        return NULL;
    if (n == v->capacity)
        return v;
    int *new_data = realloc(v->data, n * sizeof(int));
    if (!new_data && n > 0)
        return NULL;
    v->data = new_data;
    v->capacity = n;
    if (v->size > n)
        v->size = n;
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;
    if (v->size >= v->capacity)
    {
        size_t new_cap = v->capacity == 0 ? 1 : v->capacity * 2;
        if (!vector_resize(v, new_cap))
            return NULL;
    }
    v->data[v->size] = elt;
    v->size++;
    return v;
}

void vector_print(const struct vector *v)
{
    if (!v || v->size == 0)
    {
        putchar('\n');
        return;
    }
    for (size_t i = 0; i < v->size; i++)
    {
        if (i > 0)
            putchar(',');
        printf("%d", v->data[i]);
    }
    putchar('\n');
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (!v)
        return NULL;
    free(v->data);
    v->data = malloc(n * sizeof(int));
    if (!v->data && n > 0)
    {
        v->size = 0;
        v->capacity = 0;
        return NULL;
    }
    v->size = 0;
    v->capacity = n;
    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || i > v->size)
        return NULL;
    if (i == v->size)
        return vector_append(v, elt);
    if (v->size >= v->capacity)
    {
        size_t new_cap = v->capacity == 0 ? 1 : v->capacity * 2;
        if (!vector_resize(v, new_cap))
            return NULL;
    }
    for (size_t j = v->size; j > i; j--)
    {
        v->data[j] = v->data[j - 1];
    }
    v->data[i] = elt;
    v->size++;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i >= v->size)
        return NULL;
    for (size_t j = i; j < v->size - 1; j++)
    {
        v->data[j] = v->data[j + 1];
    }
    v->size--;
    if (v->capacity > 1 && v->size < v->capacity / 2)
    {
        size_t new_cap = v->capacity / 2;
        vector_resize(v, new_cap);
    }
    return v;
}
