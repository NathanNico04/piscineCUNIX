#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    struct dlist_item *new_item = malloc(sizeof(struct dlist_item));
    if (!new_item)
        return 0;

    new_item->data = element;
    new_item->next = list->head;
    new_item->prev = NULL;

    if (list->head)
        list->head->prev = new_item;
    else
        list->tail = new_item;

    list->head = new_item;
    list->size++;

    return 1;
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    struct dlist_item *new_item = malloc(sizeof(struct dlist_item));
    if (!new_item)
        return 0;

    new_item->data = element;
    new_item->next = NULL;
    new_item->prev = list->tail;

    if (list->tail)
        list->tail->next = new_item;
    else
        list->head = new_item;

    list->tail = new_item;
    list->size++;

    return 1;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *current = list->head;

    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

int dlist_get(const struct dlist *list, size_t index)
{
    if (index >= list->size)
        return -1;

    struct dlist_item *current;
    size_t i;

    if (index < list->size / 2)
    {
        current = list->head;
        for (i = 0; i < index; i++)
            current = current->next;
    }
    else
    {
        current = list->tail;
        for (i = list->size - 1; i > index; i--)
            current = current->prev;
    }

    return current->data;
}

int dlist_find(const struct dlist *list, int element)
{
    struct dlist_item *current = list->head;
    size_t index = 0;

    while (current)
    {
        if (current->data == element)
            return index;
        current = current->next;
        index++;
    }

    return -1;
}

void dlist_clear(struct dlist *list)
{
    struct dlist_item *current = list->head;
    struct dlist_item *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
