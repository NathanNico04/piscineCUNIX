#include "vigenere.h"

static int my_strlen(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

static char to_upper_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void cipher(const char *key, const char *msg, char *res)
{
    int k_len = my_strlen(key);
    int k_idx = 0;
    int i = 0;

    while (msg[i] != '\0')
    {
        char m = to_upper_char(msg[i]);
        if (m >= 'A' && m <= 'Z')
        {
            char ky = to_upper_char(key[k_idx % k_len]);
            int m_val = m - 'A';
            int ky_val = ky - 'A';
            res[i] = ((m_val + ky_val) % 26) + 'A';
            k_idx++;
        }
        else
        {
            res[i] = msg[i];
        }
        i++;
    }
    res[i] = '\0';
}

void decipher(const char *key, const char *msg, char *res)
{
    int k_len = my_strlen(key);
    int k_idx = 0;
    int i = 0;

    while (msg[i] != '\0')
    {
        char m = to_upper_char(msg[i]);
        if (m >= 'A' && m <= 'Z')
        {
            char ky = to_upper_char(key[k_idx % k_len]);
            int m_val = m - 'A';
            int ky_val = ky - 'A';
            int res_val = (m_val - ky_val) % 26;
            if (res_val < 0)
                res_val += 26;
            res[i] = res_val + 'A';
            k_idx++;
        }
        else
        {
            res[i] = msg[i];
        }
        i++;
    }
    res[i] = '\0';
}
