#include "binary_tree_dynamic.h"

int printf(const char *format, ...);

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;

    printf("%d ", tree->data);
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
}
