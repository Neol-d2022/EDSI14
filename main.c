#include <string.h>
#include <stdio.h>

#include "queue.h"
#include "stack.h"
#include "mm.h"

/* Test script */
int main(int argc, char **argv)
{
    Queue_t q, pq;
    Stack_t s;
    int i;

    QueueInit(&q);
    QueueInit(&pq);
    QueueSetComparer(&pq, (int (*)(const void *a, const void *b))strcmp);
    StackInit(&s);

    for (i = 0; i < argc; i += 1)
    {
        QueueEnqueue(&q, argv[i]);
        QueueEnqueue(&pq, argv[i]);
        StackAdd(&s, argv[i]);
    }

    printf("Standard Queue (count = %u, MDEBUG = %u):\n", QueueCount(&q), (unsigned int)MDebug());
    while (!QueueEmpty(&q))
    {
        printf("%s\n", (char *)QueueDequeue(&q));
    }
    printf("MDEBUG = %u\n", (unsigned int)MDebug());

    printf("Priority Queue (count = %u, MDEBUG = %u):\n", QueueCount(&pq), (unsigned int)MDebug());
    while (!QueueEmpty(&pq))
    {
        printf("%s\n", (char *)QueueDequeue(&pq));
    }
    printf("MDEBUG = %u\n", (unsigned int)MDebug());

    printf("Stack (count = %u, MDEBUG = %u):\n", StackCount(&s), (unsigned int)MDebug());
    while (!StackEmpty(&s))
    {
        printf("%s\n", (char *)StackPop(&s));
    }
    printf("MDEBUG = %u\n", (unsigned int)MDebug());

    QueueDeInit(&q);
    QueueDeInit(&pq);
    StackDeInit(&s);

    printf("MDEBUG = %u\n", (unsigned int)MDebug());

    return 0;
}
