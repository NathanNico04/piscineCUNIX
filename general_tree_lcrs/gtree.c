#include "gtree.h"

#include <stdlib.h>

struct gtree *gtree_create_node(char data)
{
    struct gtree *node = calloc(1, sizeof(struct gtree));
    if (!node)
    {
        return NULL;
    }
    node->data = data;
    return node;
}

int gtree_add_child(struct gtree *parent, struct gtree *child)
{
    if (!parent || !child)
    {
        return 0;
    }
    struct gtree **link = &parent->child;
    while (*link)
    {
        link = &(*link)->sibling;
    }
    *link = child;
    return 1;
}

struct gtree *gtree_search_node(struct gtree *root, const char data)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    for (struct gtree *cur = root->child; cur; cur = cur->sibling)
    {
        struct gtree *found = gtree_search_node(cur, data);
        if (found)
        {
            return found;
        }
    }
    return NULL;
}

void gtree_free(struct gtree *root)
{
    if (!root)
    {
        return;
    }
    struct gtree *cur = root->child;
    while (cur)
    {
        struct gtree *next = cur->sibling;
        gtree_free(cur);
        cur = next;
    }
    free(root);
}

static int del_in_children(struct gtree *parent, char data)
{
    struct gtree **link = &parent->child;
    while (*link)
    {
        struct gtree *cur = *link;
        if (cur->data == data)
        {
            *link = cur->sibling;
            cur->sibling = NULL;
            gtree_free(cur);
            return 1;
        }
        if (del_in_children(cur, data))
        {
            return 1;
        }
        link = &cur->sibling;
    }
    return 0;
}

int gtree_del_node(struct gtree *root, const char data)
{
    if (!root)
    {
        return 0;
    }
    if (root->data == data)
    {
        return -1;
    }
    return del_in_children(root, data);
}
