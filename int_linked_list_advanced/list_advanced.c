#include <stddef.h>
#include <stdlib.h>

#include "list.h"

struct list *get_node(struct list *list, size_t index)
{
    struct list *tmp = list;
    size_t i = 0;

    while (tmp->next != NULL && i < index - 1)
    {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

struct list *remove_head(struct list *list)
{
    struct list *next = list->next;
    free(list);
    return next;
}

void remove_after(struct list *node)
{
    struct list *to_remove = node->next;
    if (to_remove != NULL)
    {
        node->next = to_remove->next;
        free(to_remove);
    }
}

struct list *list_insert(struct list *list, int value, size_t index)
{
    if (index == 0)
        return list_prepend(list, value);

    struct list *tmp = list;
    size_t i = 0;
    while (tmp != NULL && i < index - 1)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
        return list_append(list, value);

    struct list *node = malloc(sizeof(struct list));
    if (!node)
        return NULL;

    node->data = value;
    node->next = tmp->next;
    tmp->next = node;

    return list;
}

struct list *list_remove(struct list *list, size_t index)
{
    if (list == NULL)
        return NULL;

    if (index == 0)
        return remove_head(list);

    struct list *prec = get_node(list, index);
    if (prec->next == NULL)
        return list;

    remove_after(prec);
    return list;
}

int list_find(struct list *list, int value)
{
    int i = 0;
    while (list != NULL)
    {
        if (list->data == value)
            return i;
        list = list->next;
        i++;
    }
    return -1;
}

struct list *list_concat(struct list *list, struct list *list2)
{
    if (list == NULL)
        return list2;
    struct list *tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = list2;

    return list;
}
