#include "string_replace.h"

#include <stddef.h>
#include <stdlib.h>

static size_t my_strlen(const char *s)
{
    if (s == NULL)
        return 0;
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    if (str == NULL)
        return NULL;

    size_t pat_len = my_strlen(pattern);
    size_t new_len = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
            new_len += pat_len;
        else
            new_len += 1;
    }

    char *res = malloc(new_len + 1);
    if (res == NULL)
        return NULL;

    size_t j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            if (pattern != NULL)
            {
                for (size_t k = 0; pattern[k] != '\0'; k++)
                {
                    res[j++] = pattern[k];
                }
            }
        }
        else
        {
            res[j++] = str[i];
        }
    }
    res[j] = '\0';
    return res;
}
