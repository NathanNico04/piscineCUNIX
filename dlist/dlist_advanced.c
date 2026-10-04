#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *current = list->head;

    while (current)
    {
        current->data = current->data * current->data;
        current = current->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *current = list->head;
    struct dlist_item *temp;

    list->tail = list->head;

    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        list->head = current;
        current = current->prev;
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index > list->size)
        return NULL;

    struct dlist *new_list = dlist_init();
    if (!new_list)
        return NULL;

    if (index == list->size || list->size == 0)
        return new_list;

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

    new_list->head = current;
    new_list->tail = list->tail;
    new_list->size = list->size - index;

    list->tail = current->prev;
    list->size = index;

    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;

    if (new_list->head)
        new_list->head->prev = NULL;

    return new_list;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list2->size == 0)
        return;

    if (list1->size == 0)
    {
        list1->head = list2->head;
        list1->tail = list2->tail;
        list1->size = list2->size;
    }
    else
    {
        list1->tail->next = list2->head;
        list2->head->prev = list1->tail;
        list1->tail = list2->tail;
        list1->size += list2->size;
    }

    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
