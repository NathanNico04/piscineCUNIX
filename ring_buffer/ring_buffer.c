#include "ring_buffer.h"

#include <stdlib.h>
#include <string.h>

struct ring_buf *rb_create(size_t element_size)
{
    struct ring_buf *rb = malloc(sizeof(struct ring_buf));

    if (rb == NULL)
        return NULL;

    rb->start = 0;
    rb->end = 0;
    rb->size = 0;
    rb->element_size = element_size;

    return rb;
}

int rb_push(struct ring_buf *rb, void *el)
{
    if (el == NULL)
        return 1;
    if (rb->size + rb->element_size > RING_BUF_CAPACITY)
        return 1;

    size_t first_part = RING_BUF_CAPACITY - rb->end;

    if (first_part >= rb->element_size)
    {
        memcpy(rb->elements + rb->end, el, rb->element_size);
    }
    else
    {
        char *ptr = el;
        memcpy(rb->elements + rb->end, el, first_part);
        memcpy(rb->elements, ptr + first_part, rb->element_size - first_part);
    }

    rb->end = (rb->end + rb->element_size) % RING_BUF_CAPACITY;
    rb->size += rb->element_size;

    return 0;
}

void *rb_pop(struct ring_buf *rb, void *pop)
{
    if (rb->size == 0)
        return NULL;

    size_t first_part = RING_BUF_CAPACITY - rb->start;

    if (first_part >= rb->element_size)
    {
        memcpy(pop, rb->elements + rb->start, rb->element_size);
    }
    else
    {
        char *ptr = pop;
        memcpy(pop, rb->elements + rb->start, first_part);
        memcpy(ptr + first_part, rb->elements, rb->element_size - first_part);
    }

    rb->start = (rb->start + rb->element_size) % RING_BUF_CAPACITY;
    rb->size -= rb->element_size;

    return pop;
}

void rb_clear(struct ring_buf *rb)
{
    rb->size = 0;
    rb->start = 0;
    rb->end = 0;
}
