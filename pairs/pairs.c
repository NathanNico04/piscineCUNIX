#include "pairs.h"

struct pair three_pairs_sum(const struct pair pair_1, const struct pair pair_2,
                            const struct pair pair_3)
{
    int x = pair_1.x + pair_2.x + pair_3.x;
    int y = pair_1.y + pair_2.y + pair_3.y;

    struct pair new_pair;
    new_pair.x = x;
    new_pair.y = y;

    return new_pair;
}

struct pair pairs_sum(const struct pair pairs[], size_t size)
{
    size_t i = 0;
    int new_x = 0;
    int new_y = 0;
    struct pair new_pair;
    while (i != size)
    {
        new_x += pairs[i].x;
        new_y += pairs[i].y;
        i++;
    }
    new_pair.x = new_x;
    new_pair.y = new_y;

    return new_pair;
}
