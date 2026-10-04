#include "variant.h"

#include <stdio.h>
#include <string.h>

int size_t_to_int(size_t n)
{
    int i = 0;
    size_t l = 0;

    while (l != n)
    {
        i++;
        l++;
    }
    return i;
}

void variant_display(const struct variant *e)
{
    if (!e)
        return;
    switch (e->type)
    {
    case TYPE_INT:
        printf("%i\n", e->value.int_v);
        break;

    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;

    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;

    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    }
}

static bool check_int(const struct variant *variant, union type_any value)
{
    if (!variant)
        return false;
    return (variant->type == TYPE_INT && variant->value.int_v == value.int_v);
}

static bool check_float(const struct variant *variant, union type_any value)
{
    if (!variant)
        return false;
    return (variant->type == TYPE_FLOAT
            && variant->value.float_v == value.float_v);
}

static bool check_char(const struct variant *variant, union type_any value)
{
    if (!variant)
        return false;
    return (variant->type == TYPE_CHAR
            && variant->value.char_v == value.char_v);
}

static bool check_string(const struct variant *variant, union type_any value)
{
    if (!variant)
        return false;
    return (variant->type == TYPE_STRING
            && !strcmp(variant->value.str_v, value.str_v));
}

static bool variant_has(const struct variant *variant, enum type type,
                        union type_any value)
{
    if (!variant)
        return false;
    if (variant->type != type)
        return false;

    return (check_int(variant, value) || check_float(variant, value)
            || check_char(variant, value) || check_string(variant, value));
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (!left && !right)
        return true;
    if (!right)
        return false;
    return variant_has(left, right->type, right->value);
}

float variant_sum(const struct variant *array, size_t len)
{
    float sum = 0.0f;
    size_t i = 0;

    while (i < len)
    {
        if (array[i].type == TYPE_INT)
            sum += array[i].value.int_v;
        else if (array[i].type == TYPE_FLOAT)
            sum += array[i].value.float_v;
        i++;
    }

    return sum;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    size_t i = 0;
    while (i < len)
    {
        struct variant tmp;
        tmp.type = type;
        tmp.value = value;
        if (variant_equal(&array[i], &tmp))
            return size_t_to_int(i);
        i++;
    }
    return -1;
}
