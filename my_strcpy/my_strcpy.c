#include "my_strcpy.h"

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

char *my_strcpy(char *dest, const char *source)
{
    size_t i = 0;
    size_t len = my_strlen(source);

    while (i <= len)
    {
        dest[i] = source[i];
        i++;
    }
    return dest;
}
