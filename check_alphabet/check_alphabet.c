#include "check_alphabet.h"

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL || alphabet[0] == '\0')
        return 1;

    size_t i = 0;

    while (alphabet[i] != '\0')
    {
        size_t j = 0;
        while (str[j] != '\0')
        {
            if (str[j] == alphabet[i])
                break;
            j++;
        }

        if (str[j] == '\0')
            return 0;

        i++;
    }

    return 1;
}
