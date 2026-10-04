#include "binary_tree_dynamic.h"

int is_perfect(const struct binary_tree *tree)
{
    int h = height(tree);
    size_t one = 1;
    size_t expected_size = (one << (h + 1)) - 1;

    return size(tree) == expected_size;
}
