#include <stddef.h>
#include <stdlib.h>

#include "list.h"

void swap_values(struct list *a, struct list *b)
{
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

struct list *list_sort(struct list *list)
{
    if (list == NULL)
        return NULL;

    struct list *i = list;
    while (i != NULL)
    {
        struct list *mini = i;
        struct list *j = i->next;

        while (j != NULL)
        {
            if (j->data < mini->data)
                mini = j;
            j = j->next;
        }

        if (mini != i)
            swap_values(i, mini);

        i = i->next;
    }

    return list;
}

struct list *list_reverse(struct list *list)
{
    struct list *prec = NULL;
    struct list *current = list;
    struct list *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prec;
        prec = current;
        current = next;
    }
    return prec;
}

struct list *list_split(struct list *list, size_t index)
{
    if (list == NULL)
        return NULL;

    size_t i = 0;

    while (list != NULL && i < index)
    {
        if (list->next == NULL && i < index)
            return NULL;
        list = list->next;
        i++;
    }

    if (list == NULL)
        return NULL;

    struct list *deuxieme_part = list->next;
    list->next = NULL;

    return deuxieme_part;
}
