#include "binary_tree_dynamic.h"

int printf(const char *format, ...);

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;

    dfs_print_infix(tree->left);
    printf("%d ", tree->data);
    dfs_print_infix(tree->right);
}
