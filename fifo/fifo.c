#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *fifo = malloc(sizeof(struct fifo));

    if (fifo == NULL)
        return NULL;

    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;

    return fifo;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *node = malloc(sizeof(struct list));

    if (node == NULL)
        return;

    node->data = elt;
    node->next = NULL;

    if (fifo->tail == NULL)
        fifo->head = node;
    else
        fifo->tail->next = node;

    fifo->tail = node;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    struct list *old_head = fifo->head;

    if (old_head == NULL)
        return;

    fifo->head = old_head->next;
    if (fifo->head == NULL)
        fifo->tail = NULL;

    free(old_head);
    fifo->size--;
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->head != NULL)
        fifo_pop(fifo);
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *node = fifo->head;

    while (node != NULL)
    {
        printf("%d\n", node->data);
        node = node->next;
    }
}
