#include "is_set.h"

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int mask = 1 << (n - 1);

    if (value & mask)
        return 1;
    return 0;
}
