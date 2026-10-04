#include <stddef.h>

int test_alnum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    size_t len = my_strlen(s);

    if (len == 0)
        return 1;
    if (len == 1)
        return 1;

    size_t start = 0;
    size_t end = len;

    while (start < end)
    {
        while (start < end && !test_alnum(s[start]))
            start++;
        while (start < end && !test_alnum(s[end]))
            end--;

        if (s[start] != s[end])
            return 0;

        start++;
        end--;
    }

    return 1;
}
