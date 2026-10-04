#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

static struct node *create_node(enum node_type type, int value,
                                struct node *left, struct node *right)
{
    struct node *node = calloc(1, sizeof(struct node));
    if (!node)
    {
        ast_delete(left);
        ast_delete(right);
        return NULL;
    }
    node->type = type;
    node->value = value;
    node->left_child = left;
    node->right_child = right;
    return node;
}

static struct node *make_binary(enum node_type type, struct node *left,
                                struct node *right)
{
    if (!left || !right)
    {
        ast_delete(left);
        ast_delete(right);
        return NULL;
    }
    return create_node(type, 0, left, right);
}

static struct node *parse_number(const char **cursor)
{
    int value = atoi(*cursor);
    if (**cursor == '-')
    {
        *cursor += 1;
    }
    while (**cursor >= '0' && **cursor <= '9')
    {
        *cursor += 1;
    }
    return create_node(NUMBER, value, NULL, NULL);
}

static struct node *parse_product(const char **cursor)
{
    struct node *left = parse_number(cursor);
    while (left && **cursor == '*')
    {
        *cursor += 1;
        left = make_binary(MULTI, left, parse_number(cursor));
    }
    return left;
}

static struct node *parse_sum(const char **cursor)
{
    struct node *left = parse_product(cursor);
    while (left && **cursor == '+')
    {
        *cursor += 1;
        left = make_binary(ADD, left, parse_product(cursor));
    }
    return left;
}

struct node *ast_build(const char *filename)
{
    if (!filename)
    {
        return NULL;
    }
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return NULL;
    }
    char *line = NULL;
    size_t size = 0;
    struct node *root = NULL;
    if (getline(&line, &size, file) != -1)
    {
        const char *cursor = line;
        root = parse_sum(&cursor);
    }
    free(line);
    fclose(file);
    return root;
}

void ast_delete(struct node *root)
{
    if (!root)
    {
        return;
    }
    ast_delete(root->left_child);
    ast_delete(root->right_child);
    free(root);
}
