#include "my_c_tail.h"

#include <stdlib.h>
#include <unistd.h>

#define CHUNK 4096

static char *read_all(size_t *out_size)
{
    size_t capacity = CHUNK;
    size_t size = 0;
    char *buffer = malloc(capacity);

    if (buffer == NULL)
        return NULL;

    ssize_t r = read(0, buffer + size, capacity - size);

    while (r > 0)
    {
        size += r;
        if (size == capacity)
        {
            capacity = capacity * 2;
            buffer = realloc(buffer, capacity);
            if (buffer == NULL)
                return NULL;
        }
        r = read(0, buffer + size, capacity - size);
    }

    *out_size = size;
    return buffer;
}

void stdintail(unsigned int n)
{
    size_t size = 0;
    char *buffer = read_all(&size);

    if (buffer == NULL || size == 0)
    {
        free(buffer);
        return;
    }

    size_t start = size;
    unsigned int lines = 0;

    while (start > 0 && lines < n)
    {
        start--;
        if (buffer[start] == '\n')
        {
            if (start != size - 1)
                lines++;
        }
    }

    if (start > 0)
        start++;

    write(1, buffer + start, size - start);

    free(buffer);
}
