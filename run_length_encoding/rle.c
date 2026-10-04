#include <stddef.h>
#include <stdlib.h>

struct rle_buf
{
    char *data;
    size_t len;
    size_t cap;
};

static int buf_push(struct rle_buf *b, char c)
{
    char *tmp;

    if (b->len + 1 >= b->cap)
    {
        b->cap = (b->cap == 0) ? 16 : b->cap * 2;
        tmp = realloc(b->data, b->cap);
        if (tmp == NULL)
        {
            free(b->data);
            b->data = NULL;
            return -1;
        }
        b->data = tmp;
    }
    b->data[b->len] = c;
    b->len++;
    return 0;
}

static int append_run(struct rle_buf *b, char c, size_t count)
{
    size_t j;

    j = 0;
    while (j < count)
    {
        if (buf_push(b, c) == -1)
            return -1;
        j++;
    }
    return 0;
}

static int read_pair(const char *s, size_t *i, size_t *count, char *c)
{
    if (s[*i] < '1' || s[*i] > '9')
        return -1;
    *count = s[*i] - '0';
    (*i)++;
    if (s[*i] == '\0')
        return -1;
    *c = s[*i];
    (*i)++;
    return 0;
}

char *rle_encode(const char *s)
{
    struct rle_buf b;
    size_t i;
    size_t count;
    char c;

    if (s == NULL)
        return NULL;

    b.data = NULL;
    b.len = 0;
    b.cap = 0;
    i = 0;
    while (s[i] != '\0')
    {
        c = s[i];
        count = 0;
        while (s[i] == c && count < 9)
        {
            count++;
            i++;
        }
        if (buf_push(&b, '0' + count) == -1)
            return NULL;
        if (buf_push(&b, c) == -1)
            return NULL;
    }
    if (buf_push(&b, '\0') == -1)
        return NULL;
    return b.data;
}

char *rle_decode(const char *s)
{
    struct rle_buf b;
    size_t i;
    size_t count;
    char c;

    if (s == NULL)
        return NULL;

    b.data = NULL;
    b.len = 0;
    b.cap = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (read_pair(s, &i, &count, &c) == -1)
        {
            free(b.data);
            return NULL;
        }
        if (append_run(&b, c, count) == -1)
            return NULL;
    }
    if (buf_push(&b, '\0') == -1)
        return NULL;
    return b.data;
}
