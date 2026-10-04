#include "my_strcasecmp.h"

static int to_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    int c1;
    int c2;

    while (*s1 != '\0' || *s2 != '\0')
    {
        c1 = to_lower(*s1);
        c2 = to_lower(*s2);
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return 0;
}
