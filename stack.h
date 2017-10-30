#ifndef _STACK_H_LOADED
#define _STACK_H_LOADED

#include <stddef.h>
#include <stdbool.h>

typedef struct StackNode_struct_t
{
    void *data;
    struct StackNode_struct_t *next;
} StackNode_t;

typedef struct
{
    StackNode_t *head;
    size_t count;
} Stack_t;

/* Initialize a stack object */
void StackInit(Stack_t *s);

/* De-initialize a stack object */
/* You may need to destroy / deallocate the data store by it */
void StackDeInit(Stack_t *s);

/* Check whether the stack is empty */
bool StackEmpty(Stack_t *s);

/* Add data to the stack */
void StackAdd(Stack_t *s, void *data);

/* Pop stack */
/* ABORT ON EMPTY STACK */
void *StackPop(Stack_t *s);

/* Return items count of a stack */
size_t StackCount(Stack_t *s);

/* Extension of StackDeInit */
/* dataReleaser will be call to destroy / deallocate elements if it is not NULL */
/* Additional parameter can be passed by using param */
void StackDeInitX(Stack_t *s, void *param, void (*dataReleaser)(void *data, void *param));

#endif
