#include "my_strspn.h"

size_t my_strspn(const char *s, const char *accept)
{
    size_t count = 0;
    size_t i = 0;

    if (s == NULL || accept == NULL)
        return 0;

    while (s[i] != '\0')
    {
        size_t j = 0;
        int found = 0;

        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
            {
                found = 1;
                break;
            }
            j++;
        }

        if (!found)
            break;

        count++;
        i++;
    }

    return count;
}
