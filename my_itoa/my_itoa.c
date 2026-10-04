#include <stddef.h>

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

char int_to_ascii(int value)
{
    return value + '0';
}

char *my_itoa(int value, char *s)
{
    size_t i = 0;
    int last_chiffre;
    int neg = 0;

    if (value == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    if (value < 0)
    {
        neg = 1;
        value *= -1;
    }

    while (value > 0)
    {
        last_chiffre = value % 10;
        s[i] = int_to_ascii(last_chiffre);
        i++;
        value /= 10;
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
