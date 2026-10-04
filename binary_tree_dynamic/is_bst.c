#include "binary_tree_dynamic.h"

struct bounds
{
    int has_max;
    int max_incl;
    int has_min;
    int min_excl;
};

static int is_bst_helper(const struct binary_tree *tree, struct bounds b)
{
    struct bounds left_b;
    struct bounds right_b;

    if (tree == NULL)
        return 1;

    if (b.has_max && tree->data > b.max_incl)
        return 0;
    if (b.has_min && tree->data <= b.min_excl)
        return 0;

    left_b.has_max = 1;
    left_b.max_incl = tree->data;
    left_b.has_min = b.has_min;
    left_b.min_excl = b.min_excl;

    right_b.has_max = b.has_max;
    right_b.max_incl = b.max_incl;
    right_b.has_min = 1;
    right_b.min_excl = tree->data;

    if (!is_bst_helper(tree->left, left_b))
        return 0;
    if (!is_bst_helper(tree->right, right_b))
        return 0;

    return 1;
}

int is_bst(const struct binary_tree *tree)
{
    struct bounds b;

    b.has_max = 0;
    b.max_incl = 0;
    b.has_min = 0;
    b.min_excl = 0;

    return is_bst_helper(tree, b);
}
