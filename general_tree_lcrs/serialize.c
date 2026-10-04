#include "serialize.h"

#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 64

static void write_edges(FILE *file, const struct gtree *node)
{
    for (const struct gtree *cur = node->child; cur; cur = cur->sibling)
    {
        fprintf(file, "    %c -> %c;\n", node->data, cur->data);
    }
    for (const struct gtree *cur = node->child; cur; cur = cur->sibling)
    {
        write_edges(file, cur);
    }
}

int gtree_serialize(const char *filename, const struct gtree *root)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        return -1;
    }
    fprintf(file, "digraph tree {\n");
    if (root && !root->child)
    {
        fprintf(file, "    %c;\n", root->data);
    }
    if (root)
    {
        write_edges(file, root);
    }
    fprintf(file, "}\n");
    fclose(file);
    return 0;
}

static int add_edge(struct gtree **root, char parent_data, char child_data)
{
    if (!*root)
    {
        *root = gtree_create_node(parent_data);
        if (!*root)
        {
            return 0;
        }
    }
    struct gtree *parent = gtree_search_node(*root, parent_data);
    struct gtree *child = gtree_create_node(child_data);
    if (!child || !gtree_add_child(parent, child))
    {
        free(child);
        return 0;
    }
    return 1;
}

static int parse_line(struct gtree **root, const char *line)
{
    char parent_data;
    char child_data;
    if (sscanf(line, " %c -> %c;", &parent_data, &child_data) == 2)
    {
        return add_edge(root, parent_data, child_data);
    }
    if (sscanf(line, " %c;", &parent_data) == 1)
    {
        *root = gtree_create_node(parent_data);
        return *root != NULL;
    }
    return 1;
}

struct gtree *gtree_deserialize(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return NULL;
    }
    char line[LINE_SIZE];
    struct gtree *root = NULL;
    int ok = fgets(line, LINE_SIZE, file) != NULL;
    while (ok && fgets(line, LINE_SIZE, file) && line[0] != '}')
    {
        ok = parse_line(&root, line);
    }
    fclose(file);
    if (!ok)
    {
        gtree_free(root);
        return NULL;
    }
    return root;
}
