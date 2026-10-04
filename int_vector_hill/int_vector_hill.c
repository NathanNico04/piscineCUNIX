#include "int_vector_hill.h"

static int has_negative(struct int_vector vec)
{
    size_t i = 0;

    while (i < vec.size)
    {
        if (vec.data[i] < 0)
            return 1;
        i++;
    }
    return 0;
}

static int find_max(struct int_vector vec)
{
    int max = vec.data[0];
    size_t i = 1;

    while (i < vec.size)
    {
        if (vec.data[i] > max)
            max = vec.data[i];
        i++;
    }
    return max;
}

static size_t find_first_index(struct int_vector vec, int value)
{
    size_t i = 0;

    while (vec.data[i] != value)
        i++;
    return i;
}

static int is_non_decreasing(struct int_vector vec, size_t peak)
{
    size_t i = 0;

    while (i < peak)
    {
        if (vec.data[i] > vec.data[i + 1])
            return 0;
        i++;
    }
    return 1;
}

static int is_non_increasing(struct int_vector vec, size_t peak)
{
    size_t i = peak;

    while (i + 1 < vec.size)
    {
        if (vec.data[i] < vec.data[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0 || has_negative(vec))
        return -1;

    int max = find_max(vec);
    size_t peak = find_first_index(vec, max);

    if (!is_non_decreasing(vec, peak))
        return -1;
    if (!is_non_increasing(vec, peak))
        return -1;

    return peak;
}
