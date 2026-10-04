#include "my_atoi_base.h"

int size_t_to_int(size_t n)
{
    size_t i = 0;
    int convert = 0;
    while (i != n)
    {
        convert++;
        i++;
    }
    return convert;
}

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
        || c == '\f')
        return 1;
    return 0;
}

int index_in_base(char c, const char *base)
{
    size_t i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == c)
            return size_t_to_int(i);
        i++;
    }
    return -1;
}

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int my_atoi_base(const char *str, const char *base)
{
    if (str == NULL || base == NULL || my_strlen(base) == 0)
        return 0;

    size_t i = 0;
    int sign = 1;
    int res = 0;
    size_t base_len = my_strlen(base);

    while (is_space(str[i]))
        i++;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;

        if (is_space(str[i]))
            return 0;
    }

    int digit = index_in_base(str[i], base);
    if (digit == -1)
        return 0;

    while (str[i] != '\0')
    {
        digit = index_in_base(str[i], base);
        if (digit == -1)
            return 0;

        res = res * size_t_to_int(base_len) + digit;
        i++;
    }

    return res * sign;
}
