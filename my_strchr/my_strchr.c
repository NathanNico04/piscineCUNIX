#include "my_strchr.h"

#include <stddef.h>

char *my_strchr(char *s, int c)
{
    while (*s != c)
    {
        if (*s == '\0')
            return NULL;
        s++;
    }
    return s;
}
