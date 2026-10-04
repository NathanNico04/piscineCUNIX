#include "dlist.h"

#include <stdlib.h>

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
    if (!list)
        return 0;
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    item->data = element;
    item->prev = NULL;
    item->next = list->head;

    if (list->head)
        list->head->prev = item;
    else
        list->tail = item;
    list->head = item;
    list->size++;
    return 1;
}

int dlist_push_back(struct dlist *list, int element)
{
    if (!list)
        return 0;
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    item->data = element;
    item->next = NULL;
    item->prev = list->tail;

    if (list->tail)
        list->tail->next = item;
    else
        list->head = item;
    list->tail = item;
    list->size++;
    return 1;
}

void dlist_shift(struct dlist *list, int offset)
{
    if (!list || list->size <= 1)
        return;

    long long len = (long long)list->size;
    long long off = offset % len;
    if (off < 0)
        off = len + off;

    for (long long i = 0; i < off; i++)
    {
        struct dlist_item *t = list->tail;
        list->tail = t->prev;
        list->tail->next = NULL;

        t->prev = NULL;
        t->next = list->head;
        list->head->prev = t;
        list->head = t;
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list)
        return 0;

    if (list->size == 0 || element <= list->head->data)
        return dlist_push_front(list, element);

    if (element >= list->tail->data)
        return dlist_push_back(list, element);

    struct dlist_item *curr = list->head;
    while (curr && curr->data < element)
        curr = curr->next;

    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    item->data = element;

    item->next = curr;
    item->prev = curr->prev;
    curr->prev->next = item;
    curr->prev = item;
    list->size++;
    return 1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list || list->size == 0)
        return 0;

    struct dlist_item *curr = list->head;
    while (curr && curr->data != element)
        curr = curr->next;

    if (!curr)
        return 0;

    if (curr->prev)
        curr->prev->next = curr->next;
    else
        list->head = curr->next;

    if (curr->next)
        curr->next->prev = curr->prev;
    else
        list->tail = curr->prev;

    free(curr);
    list->size--;
    return 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (!list)
        return NULL;

    struct dlist *copy = dlist_init();
    if (!copy)
        return NULL;

    struct dlist_item *curr = list->head;
    while (curr)
    {
        if (!dlist_push_back(copy, curr->data))
        {
            // Nettoyage en cas d'échec
            while (copy->head)
            {
                struct dlist_item *tmp = copy->head;
                copy->head = copy->head->next;
                free(tmp);
            }
            free(copy);
            return NULL;
        }
        curr = curr->next;
    }
    return copy;
}

void dlist_sort(struct dlist *list)
{
    if (!list || list->size <= 1)
        return;

    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        struct dlist_item *curr = list->head;
        while (curr && curr->next)
        {
            if (curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2 || list2->size == 0)
        return;

    struct dlist_item *curr2 = list2->head;
    while (curr2)
    {
        struct dlist_item *next2 = curr2->next;
        dlist_add_sort(list1, curr2->data);
        free(curr2);
        curr2 = next2;
    }

    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
