#include <stddef.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new_node = malloc(sizeof(struct stack));
    if (new_node == NULL)
        return s;

    new_node->data = e;
    new_node->next = s;
    return new_node;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;

    struct stack *next = s->next;
    free(s);
    return next;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
