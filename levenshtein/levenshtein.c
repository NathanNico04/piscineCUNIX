#include "levenshtein.h"

size_t levenshtein(const char *s1, const char *s2)
{
    if (*s1 == '\0')
    {
        size_t len = 0;
        while (s2[len] != '\0')
        {
            len++;
        }
        return len;
    }

    if (*s2 == '\0')
    {
        size_t len = 0;
        while (s1[len] != '\0')
        {
            len++;
        }
        return len;
    }

    if (*s1 == *s2)
    {
        return levenshtein(s1 + 1, s2 + 1);
    }

    size_t del = levenshtein(s1 + 1, s2);
    size_t ins = levenshtein(s1, s2 + 1);
    size_t sub = levenshtein(s1 + 1, s2 + 1);

    size_t min = del;
    if (ins < min)
    {
        min = ins;
    }
    if (sub < min)
    {
        min = sub;
    }

    return 1 + min;
}
