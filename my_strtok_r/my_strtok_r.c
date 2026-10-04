#include "my_strtok_r.h"

static int is_delim(char c, const char *delim)
{
    for (size_t i = 0; delim[i] != '\0'; i++)
    {
        if (c == delim[i])
            return 1;
    }
    return 0;
}

static char *skip_delims(char *str, const char *delim)
{
    while (*str != '\0' && is_delim(*str, delim))
    {
        str++;
    }
    return str;
}

static char *find_token_end(char *str, const char *delim)
{
    while (*str != '\0' && !is_delim(*str, delim))
    {
        str++;
    }
    return str;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (str == NULL)
    {
        if (saveptr == NULL || *saveptr == NULL)
            return NULL;
        str = *saveptr;
    }

    str = skip_delims(str, delim);
    if (*str == '\0')
    {
        if (saveptr)
            *saveptr = NULL;
        return NULL;
    }

    char *token_start = str;
    str = find_token_end(str, delim);

    if (*str != '\0')
    {
        *str = '\0';
        if (saveptr)
            *saveptr = str + 1;
    }
    else if (saveptr)
    {
        *saveptr = NULL;
    }

    return token_start;
}
