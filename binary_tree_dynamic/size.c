#include "binary_tree_dynamic.h"

size_t size(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + size(tree->left) + size(tree->right);
}
