#include <stdlib.h>

#include "dlist.h"

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (element < 0 || index > list->size)
        return 0;

    if (index == 0)
        return dlist_push_front(list, element);

    if (index == list->size)
        return dlist_push_back(list, element);

    struct dlist_item *new_item = malloc(sizeof(struct dlist_item));
    if (!new_item)
        return 0;

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

    new_item->data = element;
    new_item->next = current;
    new_item->prev = current->prev;

    current->prev->next = new_item;
    current->prev = new_item;

    list->size++;

    return 1;
}

int dlist_remove_at(struct dlist *list, size_t index)
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

    int data = current->data;

    if (current->prev)
        current->prev->next = current->next;
    else
        list->head = current->next;

    if (current->next)
        current->next->prev = current->prev;
    else
        list->tail = current->prev;

    free(current);
    list->size--;

    return data;
}
