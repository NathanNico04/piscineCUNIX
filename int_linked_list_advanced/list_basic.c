#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list *list_prepend(struct list *list, int value)
{
    struct list *l = malloc(sizeof(struct list));
    if (!l)
    {
        return NULL;
    }
    l->data = value;
    l->next = list;
    return l;
}

size_t list_length(struct list *list)
{
    size_t len = 0;
    while (list != NULL)
    {
        len++;
        list = list->next;
    }
    return len;
}

void list_print(struct list *list)
{
    if (list == NULL)
    {
        return;
    }

    while (list != NULL)
    {
        printf("%d", list->data);
        if (list->next != NULL)
            putchar(' ');
        list = list->next;
    }
    putchar('\n');
}

void list_destroy(struct list *list)
{
    struct list *tmp;
    while (list != NULL)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

struct list *list_append(struct list *list, int value)
{
    struct list *new_node = malloc(sizeof(struct list));
    if (!new_node)
        return NULL;

    new_node->data = value;
    new_node->next = NULL;

    if (list == NULL)
        return new_node;

    struct list *tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;

    return list;
}
