#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "static_queue.h"

void init_static_queue(t_static_queue *q)
{
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
        return 0;
    if(!q->count)
    {
        q->first = 0;
        q->last = q->first + 1;
        q->info[q->first] = malloc(size);
        if(!q->info[q->first])
            return 0;
        memcpy(q->info[q->first],info, size);
    } else
    {
        q->info[q->last] = malloc(size);
        if(!q->info[q->last])
            return 0;
        memcpy(q->info[q->last],info, size);

        if(q->last == (_TAM_STATIC_QUEUE - 1))
            q->last = (q->last % (_TAM_STATIC_QUEUE - 1));
        else
            q->last = (q->last % (_TAM_STATIC_QUEUE - 1)) + 1;
    }
    q->count ++;
    return 1;
}

int pop_static_queue(t_static_queue *q, void *info, const size_t size)
{
    if(q->count == 0)
        return 0;
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
    return 1;
}

int first_static_queue (t_static_queue *q, void *info, const size_t size)
{
    if(q->first == -1)
        return 0;
    memcpy(info,q->info[q->first],size);
    return 1;
}

void clear_static_queue (t_static_queue *q)
{
    q->first = -1;
    q->last = -1;
}
