#include "binary_tree_dynamic.h"

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if (tree->left != NULL && tree->right != NULL)
        return 0;

    return is_degenerate(tree->left) && is_degenerate(tree->right);
}
