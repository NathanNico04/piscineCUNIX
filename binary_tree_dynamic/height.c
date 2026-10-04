#include "binary_tree_dynamic.h"

int height(const struct binary_tree *tree)
{
    int left_height;
    int right_height;

    if (tree == NULL)
        return -1;

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (left_height > right_height)
        return 1 + left_height;
    return 1 + right_height;
}
