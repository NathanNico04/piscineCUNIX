#include <stdio.h>

#include "rbtree.h"

void rb_infix(struct rb_node *node)
{
    if (node == NULL || node == &nil)
        return;

    rb_infix(node->left);
    printf("%c ", node->val);
    rb_infix(node->right);
}
