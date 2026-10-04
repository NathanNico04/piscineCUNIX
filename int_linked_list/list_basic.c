#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

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
