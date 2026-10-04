#include "my_itoa_base.h"

int size_t_to_int(size_t n)
{
    size_t i = 0;
    int res = 0;
    while (i != n)
    {
        res++;
        i++;
    }
    return res;
}

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void str_revert(char str[])
{
    size_t len = my_strlen(str);
    if (len == 0)
        return;

    size_t i = 0;
    size_t j = len - 1;
    while (i < j)
    {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
}

char int_to_ascii(int value, const char *base)
{
    return base[value];
}

char *my_itoa_base(int n, char *s, const char *base)
{
    size_t i = 0;
    int neg = 0;
    int base_len = size_t_to_int(my_strlen(base));

    if (n == 0)
    {
        s[0] = base[0];
        s[1] = '\0';
        return s;
    }

    if (n < 0 && base_len == 10)
    {
        neg = 1;
        n *= -1;
    }

    while (n > 0)
    {
        int digit = n % base_len;
        s[i] = int_to_ascii(digit, base);
        i++;
        n /= base_len;
    }

    if (neg)
    {
        s[i] = '-';
        i++;
    }

    s[i] = '\0';

    str_revert(s);

    return s;
}
