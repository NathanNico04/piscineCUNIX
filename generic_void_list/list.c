#include "list.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new_node = malloc(sizeof(struct list));
    if (!new_node)
        return NULL;
    new_node->data = malloc(data_size);
    if (!new_node->data)
    {
        free(new_node);
        return NULL;
    }
    memcpy(new_node->data, value, data_size);
    new_node->next = list;
    return new_node;
}

size_t list_length(struct list *list)
{
    size_t len = 0;
    struct list *curr = list;
    while (curr)
    {
        len++;
        curr = curr->next;
    }
    return len;
}

void list_destroy(struct list *list)
{
    struct list *curr = list;
    while (curr)
    {
        struct list *next = curr->next;
        free(curr->data);
        free(curr);
        curr = next;
    }
}
