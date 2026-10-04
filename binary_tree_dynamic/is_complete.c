#include "binary_tree_dynamic.h"

static int is_complete_helper(const struct binary_tree *tree, size_t index,
                              size_t n)
{
    if (tree == NULL)
        return 1;
    if (index >= n)
        return 0;

    return is_complete_helper(tree->left, 2 * index + 1, n)
        && is_complete_helper(tree->right, 2 * index + 2, n);
}

int is_complete(const struct binary_tree *tree)
{
    return is_complete_helper(tree, 0, size(tree));
}
