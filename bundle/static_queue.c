#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "static_queue.h"

void init_static_queue(t_static_queue *q)
{
    for(int i = 0; i < _TAM_STATIC_QUEUE; i++)
        q->info[i] = NULL;
    q->first = -1;
    q->last = -1;
    q->count = 0;
}

int is_empty_static_queue(t_static_queue *q)
{
    return q->first == -1;
}

int is_full_static_queue(t_static_queue *q)
{
    return q->count == _TAM_STATIC_QUEUE;
}

int push_static_queue(t_static_queue *q, const void *info, const size_t size)
{
    if(q->count == _TAM_STATIC_QUEUE)
        return _STATIC_QUEUE_FULL;
    if(!q->count)
    {
        q->first = 0;
        q->last = q->first + 1;
        q->info[q->first] = malloc(size);
        if(!q->info[q->first])
            return _STATIC_QUEUE_FULL;
        memcpy(q->info[q->first],info, size);
    } else
    {
        q->info[q->last] = malloc(size);
        if(!q->info[q->last])
            return _STATIC_QUEUE_FULL;
        memcpy(q->info[q->last],info, size);

        if(q->last == (_TAM_STATIC_QUEUE - 1))
            q->last = (q->last % (_TAM_STATIC_QUEUE - 1));
        else
            q->last = (q->last % (_TAM_STATIC_QUEUE - 1)) + 1;
    }
    q->count ++;
    return _STATIC_QUEUE_OK;
}

int pop_static_queue(t_static_queue *q, void *info, const size_t size)
{
    if(q->count == 0)
        return _STATIC_QUEUE_EMPTY;
    memcpy(info,q->info[q->first],size);
    if(q->first == (_TAM_STATIC_QUEUE - 1))
        q->first = (q->first % (_TAM_STATIC_QUEUE - 1));
    else
        q->first = (q->first % (_TAM_STATIC_QUEUE - 1)) + 1;
    q->count --;
    if(!q->count ){
        q->first = -1;
        q->last = -1;
    }
    return _STATIC_QUEUE_OK;
}

int first_static_queue (t_static_queue *q, void *info, const size_t size)
{
    if(q->first == -1)
        return _STATIC_QUEUE_EMPTY;
    memcpy(info,q->info[q->first],size);
    return _STATIC_QUEUE_OK;
}

void clear_static_queue (t_static_queue *q)
{
    for(int i = 0; i < _TAM_STATIC_QUEUE; i++)
        if(q->info[i])
            free(q->info[i]);
    q->first = -1;
    q->last = -1;
    q->count = 0;
}
