#include "binary_tree_dynamic.h"

int printf(const char *format, ...);

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;

    dfs_print_postfix(tree->left);
    dfs_print_postfix(tree->right);
    printf("%d ", tree->data);
}
