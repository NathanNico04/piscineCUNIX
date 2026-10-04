#include "str_revert.h"

static int str_len(char str[])
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

void str_revert(char str[])
{
    int len = str_len(str);
    int i = 0;
    char tmp = 0;

    while (i < len / 2)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
        i++;
    }
}