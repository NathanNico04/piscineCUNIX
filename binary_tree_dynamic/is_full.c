#include "binary_tree_dynamic.h"

int is_full(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if ((tree->left == NULL) != (tree->right == NULL))
        return 0;

    return is_full(tree->left) && is_full(tree->right);
}
