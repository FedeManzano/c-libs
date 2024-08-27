#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"



void init_static_stack(t_static_stack *s)
{
    s->top = _STATIC_STACK_EMPTY;
}

int is_empty_static_stack(const t_static_stack *s)
{
    return s->top == _STATIC_STACK_EMPTY;
}

int is_full_static_stack(const t_static_stack *s)
{
    return s->top == _STATIC_STACK_MAX_SIZE - 1;
}

int push_static_stack(t_static_stack *s, const t_info_static_stack *info)
{
    if(s->top == _STATIC_STACK_MAX_SIZE - 1)
        return _STATIC_STACK_FULL;
    s->top ++;
    s->info[s->top] = *info;
    return _STATIC_STACK_OK;
}

int pop_static_stack(t_static_stack *s, t_info_static_stack *info)
{
    if(s->top == _STATIC_STACK_EMPTY)
        return _STATIC_STACK_EMPTY;
    *info = s->info[s->top];
    s->top --;
    return _STATIC_STACK_OK;
}


int top_static_stack(t_static_stack *s, t_info_static_stack *info)
{
    if(s->top == _STATIC_STACK_EMPTY)
        return _STATIC_STACK_EMPTY;
    *info = s->info[s->top];
    return _STATIC_STACK_OK;
}

void clear_static_stack(t_static_stack *s)
{
    s->top = _STATIC_STACK_EMPTY;
}


