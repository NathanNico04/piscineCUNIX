#include "print.h"

#include <stdio.h>

static void print_descendants(const struct gtree *node)
{
    for (const struct gtree *cur = node->child; cur; cur = cur->sibling)
    {
        fprintf(stdout, " %c", cur->data);
        print_descendants(cur);
    }
}

void gtree_print_preorder(const struct gtree *root)
{
    if (!root)
    {
        return;
    }
    fprintf(stdout, "%c", root->data);
    print_descendants(root);
    fputc('\n', stdout);
}
