#include "rbtree.h"

#include <stdlib.h>

struct rb_node nil = { .color = BLACK,
                       .val = 0,
                       .left = &nil,
                       .right = &nil,
                       .parent = NULL };

struct rb_node *rb_init(char val)
{
    struct rb_node *node = malloc(sizeof(struct rb_node));
    if (!node)
        return NULL;

    node->val = val;
    node->color = RED;
    node->left = &nil;
    node->right = &nil;
    node->parent = NULL;
    return node;
}

static void rotate_left(struct rb_node **root, struct rb_node *x)
{
    struct rb_node *y = x->right;
    x->right = y->left;
    if (y->left != &nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

static void rotate_right(struct rb_node **root, struct rb_node *y)
{
    struct rb_node *x = y->left;
    y->left = x->right;
    if (x->right != &nil)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

static void insert_fixup_left(struct rb_node **root, struct rb_node **z_ptr)
{
    struct rb_node *z = *z_ptr;
    struct rb_node *y = z->parent->parent->right;
    if (y->color == RED)
    {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        *z_ptr = z->parent->parent;
    }
    else
    {
        if (z == z->parent->right)
        {
            *z_ptr = z->parent;
            rotate_left(root, *z_ptr);
        }
        (*z_ptr)->parent->color = BLACK;
        (*z_ptr)->parent->parent->color = RED;
        rotate_right(root, (*z_ptr)->parent->parent);
    }
}

static void insert_fixup_right(struct rb_node **root, struct rb_node **z_ptr)
{
    struct rb_node *z = *z_ptr;
    struct rb_node *y = z->parent->parent->left;
    if (y->color == RED)
    {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        *z_ptr = z->parent->parent;
    }
    else
    {
        if (z == z->parent->left)
        {
            *z_ptr = z->parent;
            rotate_right(root, *z_ptr);
        }
        (*z_ptr)->parent->color = BLACK;
        (*z_ptr)->parent->parent->color = RED;
        rotate_left(root, (*z_ptr)->parent->parent);
    }
}

static void insert_fixup(struct rb_node **root, struct rb_node *z)
{
    while (z->parent != NULL && z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
            insert_fixup_left(root, &z);
        else
            insert_fixup_right(root, &z);
    }
    (*root)->color = BLACK;
}

struct rb_node *rb_insert(struct rb_node *root, char c)
{
    if (root != NULL && root->parent != NULL)
        return NULL;

    struct rb_node *y = NULL;
    struct rb_node *x = root;
    while (x != NULL && x != &nil)
    {
        y = x;
        if (c == x->val)
            return root;
        x = (c < x->val) ? x->left : x->right;
    }

    struct rb_node *z = rb_init(c);
    if (!z)
        return NULL;
    z->parent = y;

    if (y == NULL)
        root = z;
    else if (c < y->val)
        y->left = z;
    else
        y->right = z;

    insert_fixup(&root, z);
    return root;
}

static void transplant(struct rb_node **root, struct rb_node *u,
                       struct rb_node *v)
{
    if (u->parent == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

static struct rb_node *minimum(struct rb_node *node)
{
    while (node->left != &nil)
        node = node->left;
    return node;
}

static void delete_fixup_left(struct rb_node **root, struct rb_node **xp)
{
    struct rb_node *x = *xp;
    struct rb_node *w = x->parent->right;
    if (w->color == RED)
    {
        w->color = BLACK;
        x->parent->color = RED;
        rotate_left(root, x->parent);
        w = x->parent->right;
    }
    if (w->left->color == BLACK && w->right->color == BLACK)
    {
        w->color = RED;
        *xp = x->parent;
    }
    else
    {
        if (w->right->color == BLACK)
        {
            w->left->color = BLACK;
            w->color = RED;
            rotate_right(root, w);
            w = x->parent->right;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->right->color = BLACK;
        rotate_left(root, x->parent);
        *xp = *root;
    }
}

static void delete_fixup_right(struct rb_node **root, struct rb_node **xp)
{
    struct rb_node *x = *xp;
    struct rb_node *w = x->parent->left;
    if (w->color == RED)
    {
        w->color = BLACK;
        x->parent->color = RED;
        rotate_right(root, x->parent);
        w = x->parent->left;
    }
    if (w->right->color == BLACK && w->left->color == BLACK)
    {
        w->color = RED;
        *xp = x->parent;
    }
    else
    {
        if (w->left->color == BLACK)
        {
            w->right->color = BLACK;
            w->color = RED;
            rotate_left(root, w);
            w = x->parent->left;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->left->color = BLACK;
        rotate_right(root, x->parent);
        *xp = *root;
    }
}

static void delete_fixup(struct rb_node **root, struct rb_node *x)
{
    while (x != *root && x->color == BLACK)
    {
        if (x == x->parent->left)
            delete_fixup_left(root, &x);
        else
            delete_fixup_right(root, &x);
    }
    x->color = BLACK;
}

struct rb_node *rb_delete(struct rb_node *root, char c)
{
    if (root == NULL || root->parent != NULL)
        return NULL;

    struct rb_node *z = root;
    while (z != &nil && z != NULL && z->val != c)
        z = (c < z->val) ? z->left : z->right;
    if (z == &nil || z == NULL)
        return NULL;

    struct rb_node *y = z;
    struct rb_node *x;
    int y_col = y->color;

    if (z->left == &nil)
    {
        x = z->right;
        transplant(&root, z, z->right);
    }
    else if (z->right == &nil)
    {
        x = z->left;
        transplant(&root, z, z->left);
    }
    else
    {
        y = minimum(z->right);
        y_col = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else
        {
            transplant(&root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(&root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);
    if (y_col == BLACK)
        delete_fixup(&root, x);
    return root;
}
