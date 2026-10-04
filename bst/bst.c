#include <stddef.h>
#include <stdlib.h>

struct bst_node
{
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_node *max_node(struct bst_node *tree)
{
    while (tree->right)
        tree = tree->right;
    return tree;
}

struct bst_node *create_node(int value)
{
    struct bst_node *node = malloc(sizeof(struct bst_node));
    if (!node)
        return NULL;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);

    if (value < tree->data)
        tree->left = add_node(tree->left, value);
    else if (value > tree->data)
        tree->right = add_node(tree->right, value);

    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (value < tree->data)
        tree->left = delete_node(tree->left, value);
    else if (value > tree->data)
        tree->right = delete_node(tree->right, value);
    else
    {
        if (!tree->left)
        {
            struct bst_node *r = tree->right;
            free(tree);
            return r;
        }
        else if (!tree->right)
        {
            struct bst_node *l = tree->left;
            free(tree);
            return l;
        }
        else
        {
            struct bst_node *maxl = max_node(tree->left);
            tree->data = maxl->data;
            tree->left = delete_node(tree->left, maxl->data);
        }
    }

    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (value == tree->data)
        return tree;
    else if (value < tree->data)
        return find(tree->left, value);
    else
        return find(tree->right, value);
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;

    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
}
