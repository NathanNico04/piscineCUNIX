#include "binary_cipher.h"

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *d = data;
    const unsigned char *k = key;
    size_t i = 0;

    while (i < data_len)
    {
        d[i] ^= k[i % key_len];
        i++;
    }
}
