#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

void init_stack(t_stack *s)
{
    *s = NULL;
}

int is_empty_stack(const t_stack *s)
{
    return *s == NULL;
}

int is_full_stack(const t_stack *s)
{
    return !malloc(sizeof(t_node_stack));
}

int push_stack(t_stack *s, const void *info, const size_t size)
{
    if(!s)
        return NULL_STACK;
    if(!info)
        return NULL_INFO;

    t_node_stack *n = (t_node_stack *)malloc(sizeof(t_node_stack));
    if(!n)
        return FULL_STACK;

    n->info = malloc(sizeof(size));
    if(!n->info)
        return FULL_STACK;

    memcpy(n->info,info,size);

    n->next = *s;
    *s = n;
    return OK;
}

int pop_stack(t_stack *s, void * info, size_t size)
{
    if(!s)
        return NULL_STACK;
    if(!info)
        return NULL_INFO;
    if(!*s)
        return EMPTY_STACK;

    memcpy(info,(*s)->info,size);

    t_node_stack *pe = *s;
    *s = pe->next;
    free(pe);
    return OK;
}

int top_stack(const t_stack *s, void *info, size_t size)
{
    if(!s)
        return NULL_STACK;
    if(!info)
        return NULL_INFO;
    if(!*s)
        return EMPTY_STACK;

    memcpy(info,(*s)->info,size);
    return OK;
}

void clear_stack(t_stack *s){
    t_node_stack *elim = *s;
    while(*s){
        *s = elim->next;
        free(elim->info);
        free(elim);
        elim = *s;
    }
}
