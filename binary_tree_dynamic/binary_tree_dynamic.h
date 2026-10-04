#ifndef BINARY_TREE_DYNAMIC_H
#define BINARY_TREE_DYNAMIC_H

#include <stddef.h>

struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
};

/*
** Returns the size of `tree`.
*/
size_t size(const struct binary_tree *tree);

/*
** Returns the height of `tree`.
*/
int height(const struct binary_tree *tree);

/*
** Print nodes of `tree` with a prefix order.
*/
void dfs_print_prefix(const struct binary_tree *tree);

/*
** Print nodes of `tree` with an infix order.
*/
void dfs_print_infix(const struct binary_tree *tree);

/*
** Print nodes of `tree` with a postfix order.
*/
void dfs_print_postfix(const struct binary_tree *tree);

/*
** Returns 1 if `tree` is perfect, 0 otherwise.
*/
int is_perfect(const struct binary_tree *tree);

/*
** Returns 1 if `tree` is complete, 0 otherwise.
*/
int is_complete(const struct binary_tree *tree);

/*
** Returns 1 if `tree` is degenerate, 0 otherwise.
*/
int is_degenerate(const struct binary_tree *tree);

/*
** Returns 1 if `tree` is full, 0 otherwise.
*/
int is_full(const struct binary_tree *tree);

/*
** Returns 1 if `tree` is a binary search tree, 0 otherwise.
*/
int is_bst(const struct binary_tree *tree);

#endif /* ! BINARY_TREE_DYNAMIC_H */
