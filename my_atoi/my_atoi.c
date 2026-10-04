#include "my_atoi.h"

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
        || c == '\f')
        return 1;
    return 0;
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

size_t skip_spaces(const char *str)
{
    size_t i = 0;
    while (is_space(str[i]))
    {
        i++;
    }
    return i;
}

int my_atoi(const char *str)
{
    if (str == NULL)
        return 0;

    size_t i = skip_spaces(str);
    int sign = 1;
    int res = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;

        if (str[i] == '+' || str[i] == '-' || is_space(str[i]))
            return 0;
    }

    if (!is_digit(str[i]))
        return 0;

    while (str[i] != '\0')
    {
        if (!is_digit(str[i]))
            return 0;

        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}
