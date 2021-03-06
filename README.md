# EDSI14
Essential Data Structure Implementation using linked-lists

## Stack API (from `stack.h`)
```c
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
```

## Queue API (from `queue.h`)
```c
/* Initialize a queue object */
/* The newly initialized queue is considered to be a standard queue */
void QueueInit(Queue_t *q);

/* De-initialize a queue object */
/* You may need to destroy / deallocate the data store by it */
void QueueDeInit(Queue_t *q);

/* Check whether the queue is empty */
bool QueueEmpty(Queue_t *q);

/* Return items count of a queue */
size_t QueueCount(Queue_t *q);

/* Assign a comparing function to a queue, make it a priority queue */
/* CAN ONLY CALL ON EMPTY QUEUE, otherwise the program aborts */
void QueueSetComparer(Queue_t *q, int (*queueDataComparer)(const void *a, const void *b));

/* Add data to the queue */
/* Complexity O(1) for standard queue */
/* Complexity O(n) for prioity queue */
void QueueEnqueue(Queue_t *q, void *data);

/* Remove the first (smallest) element */
/* ABORT ON EMPTY QUEUE */
void *QueueDequeue(Queue_t *q);
```
