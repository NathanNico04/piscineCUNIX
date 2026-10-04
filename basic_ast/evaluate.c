#include <stdio.h>

#include "ast.h"

int ast_evaluate(const struct node *root)
{
    if (!root)
    {
        return 0;
    }
    if (root->type == NUMBER)
    {
        return root->value;
    }
    int left = ast_evaluate(root->left_child);
    int right = ast_evaluate(root->right_child);
    if (root->type == ADD)
    {
        return left + right;
    }
    return left * right;
}

static void print_expression(const struct node *node)
{
    if (node->type == NUMBER)
    {
        printf("%d", node->value);
        return;
    }
    print_expression(node->left_child);
    putchar(node->type == ADD ? '+' : '*');
    print_expression(node->right_child);
}

void ast_print(const struct node *root)
{
    if (!root)
    {
        return;
    }
    print_expression(root);
    putchar('\n');
}
