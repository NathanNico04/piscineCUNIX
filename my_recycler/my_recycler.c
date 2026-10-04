#include "my_recycler.h"

void *malloc(size_t size);
void free(void *ptr);

struct recycler *recycler_create(size_t block_size, size_t total_size)
{
    if (block_size == 0 || total_size == 0)
    {
        return NULL;
    }

    if (block_size % sizeof(long double) != 0)
    {
        return NULL;
    }

    if (total_size % block_size != 0)
    {
        return NULL;
    }

    struct recycler *r = malloc(sizeof(struct recycler));

    if (r == NULL)
    {
        return NULL;
    }

    r->chunk = malloc(total_size);

    if (r->chunk == NULL)
    {
        free(r);
        return NULL;
    }

    r->block_size = block_size;
    r->capacity = total_size / block_size;

    unsigned char *base = r->chunk;
    size_t i = 0;

    while (i < r->capacity)
    {
        void *current_block = base + i * block_size;
        struct free_list *current = current_block;

        if (i + 1 < r->capacity)
        {
            void *next_block = base + (i + 1) * block_size;

            current->next = next_block;
        }
        else
        {
            current->next = NULL;
        }

        i++;
    }

    r->free = r->chunk;

    return r;
}

void recycler_destroy(struct recycler *r)
{
    if (r == NULL)
    {
        return;
    }

    free(r->chunk);
    free(r);
}

void *recycler_allocate(struct recycler *r)
{
    if (r == NULL || r->free == NULL)
    {
        return NULL;
    }

    struct free_list *block = r->free;

    r->free = block->next;

    return block;
}

void recycler_free(struct recycler *r, void *block)
{
    if (r == NULL || block == NULL)
    {
        return;
    }

    struct free_list *new_free = block;

    new_free->next = r->free;
    r->free = block;
}
