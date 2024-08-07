#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

void init_queue(t_queue * q)
{
    q->first = q->last = NULL;
}

int is_empty_queue(const t_queue * q)
{
    return q->first == NULL;
}

int is_full_queue(const t_queue * q)
{
    return !malloc(sizeof(t_node_queue));
}

int push_queue(t_queue * q,const void * info, size_t size)
{
    if(!q)
        return NULL_QUEUE;
    if(!info)
        return ERROR_INFO;

    t_node_queue * n = (t_node_queue *)malloc(sizeof(t_node_queue));
    if(!n)
        return FULL_QUEUE;

    n->info = malloc(sizeof(size));
    if(!n->info)
        return FULL_QUEUE;
    memcpy(n->info, info,size);

    n->next = NULL;
    if(!q->first )
    {
        q->first = n;
        q->last = n;
    }
    else
    {
        q->last->next = n;
        q->last = n;
    }
    return OK;
}

int pop_queue(t_queue *q, void * info, size_t size)
{
    if(!q)
        return NULL_QUEUE;
    if(!info)
        return ERROR_INFO;

    memcpy(info,q->first->info,size);

    t_node_queue *elim = q->first;

    q->first = elim->next;
    if(!q->first)
        q->last = NULL;
    free(elim);
    return OK;
}

int top_queue(const t_queue *q, void *info, size_t size)
{
    if(!q)
        return NULL_QUEUE;
    if(!info)
        return ERROR_INFO;
    if(!q->first)
        return EMPTY_QUEUE;
    memcpy(info,q->first->info,size);
    return 1;
}

void clear_queue(t_queue *q)
{
    t_node_queue *e;
    while(q->first)
    {
        e = q->first;
        q->first = e->next;
        if(!q->first)
            q->last = NULL;
        free(e);
    }
}
