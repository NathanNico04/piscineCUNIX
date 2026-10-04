#include "simple_fnmatch.h"

static int match_here(const char *pattern, const char *string)
{
    if (*pattern == '\0')
        return *string == '\0' ? 0 : FNM_NOMATCH;

    if (*pattern == '*')
    {
        while (*pattern == '*')
            pattern++;
        if (*pattern == '\0')
            return 0;
        while (*string != '\0')
        {
            if (match_here(pattern, string) == 0)
                return 0;
            string++;
        }
        return match_here(pattern, string);
    }

    if (*pattern == '\\')
    {
        if (pattern[1] == '\0')
            return FNM_NOMATCH;
        if (*string == pattern[1])
            return match_here(pattern + 2, string + 1);
        return FNM_NOMATCH;
    }

    if (*pattern == '?' || *pattern == *string)
    {
        if (*string == '\0')
            return FNM_NOMATCH;
        return match_here(pattern + 1, string + 1);
    }

    return FNM_NOMATCH;
}

int simple_fnmatch(const char *pattern, const char *string)
{
    if (!pattern || !string)
        return FNM_NOMATCH;

    return match_here(pattern, string);
}
