#include <string.h>
#include <stdlib.h>

#include "stack.h"
#include "mm.h"

void StackInit(Stack_t *s)
{
    memset(s, 0, sizeof(*s));
}

void StackDeInit(Stack_t *s)
{
    StackNode_t *c, *d;

    c = s->head;
    while (c)
    {
        d = c->next;
        Mfree(c);
        c = d;
    }
}

bool StackEmpty(Stack_t *s)
{
    return (s->count == 0) ? (true) : (false);
}

void StackAdd(Stack_t *s, void *data)
{
    StackNode_t *n;

    n = (StackNode_t *)Mmalloc(sizeof(*n));
    n->data = data;
    n->next = s->head;
    s->head = n;
    s->count += 1;
}

void *StackPop(Stack_t *s)
{
    StackNode_t *c;
    void *d;

#ifndef _EDSI_PRODUCTION
    if (s->count == 0)
        abort();
#endif

    c = s->head;
    s->head = c->next;
    s->count -= 1;
    d = c->data;
    Mfree(c);

    return d;
}

size_t StackCount(Stack_t *s)
{
    return s->count;
}

void StackDeInitX(Stack_t *s, void *param, void (*dataReleaser)(void *data, void *param))
{
    void *d;

    while (s->count != 0)
    {
        d = StackPop(s);
        dataReleaser(d, param);
    }

    StackDeInit(s);
}
