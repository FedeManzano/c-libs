#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_list.h"


void init_simple_list(t_simple_list *l)
{
    *l = NULL;
}

int is_empty_simple_list(t_simple_list *l)
{
    return *l == NULL;
}

int is_full_simple_list(t_simple_list *l)
{
    return !malloc(sizeof(t_node_simple_list));
}

int add_simple_list(t_simple_list *l, const void *info, const size_t size)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;
    if(size <= 0)
        return _SIMPLE_LIST_SIZE;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    while(*l && (*l)->next)
        l = &(*l)->next;

    n->next = NULL;

    if(*l) (*l)->next = n;
    else *l = n;

    return _SIMPLE_LIST_OK;
}

int add_first_simple_list(t_simple_list *l, const void *info, const size_t size)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    n->next = *l;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int insert_simple_list(t_simple_list *l,const void *info, size_t size,const int index)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;
    if(size <= 0)
        return _SIMPLE_LIST_SIZE;
    if(index < 0)
        return _SIMPLE_LIST_INDEX;

    if(!*l)
    {
        add_simple_list(l,info,size);
        return _SIMPLE_LIST_OK;
    }

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;

    memcpy(n->info,info,size);

    if(*l && index >= len_simple_list(l))
    {
        n->next = NULL;
        while(*l && (*l)->next)
            l = &(*l)->next;
        (*l)->next = n;
        return _SIMPLE_LIST_OK;
    }

    int ind = 0;

    while(*l && ind < index)
    {
        ind ++;
        l = &(*l)->next;
    }


    if(*l && ind == index)
    {
        n->next = *l;
        *l = n;
        return _SIMPLE_LIST_OK;
    }
    return _SIMPLE_LIST_NO_INSERT;
}

int insert_range_simple_list(t_simple_list *l,const void *arr, size_t size,const int ce, int index)
{
    int res = _SIMPLE_LIST_NO_INSERT;
    int ind = 0;
    while(ind < ce) {
        res = insert_simple_list(l,arr + ind * size,size,index);
        index ++;
        ind ++;
    }

    return res;
}

int add_simple_list_in_order(t_simple_list *l, const void *info, const size_t size, t_comp comp)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;

    if(*l && comp((*l)->info,info) > 0)
    {
        n->next = *l;
        *l = n;
        return _SIMPLE_LIST_OK;
    }

    n->next = NULL;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;


    if(*l && !comp((*l)->info,info))
    {
        free(n->info);
        free(n);
        return _SIMPLE_LIST_DUP;
    }

    if(*l && comp((*l)->info,info) > 0)
    {
        n->next = *l;
        *l = n;
        return _SIMPLE_LIST_OK;
    }

    n->next = NULL;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int try_add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;


    if(*l && !comp((*l)->info,info))
    {
        free(n->info);
        free(n);
        memcpy((*l)->info, info,size);
        return _SIMPLE_LIST_DUP;
    }

    if(*l && comp((*l)->info,info) > 0)
    {
        n->next = *l;
        *l = n;
        return _SIMPLE_LIST_OK;
    }

    n->next = NULL;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;


    if(*l && !comp((*l)->info,info))
    {
        free(n->info);
        free(n);
        update((*l)->info, info);
        return _SIMPLE_LIST_DUP;
    }

    if(*l && comp((*l)->info,info) > 0)
    {
        n->next = *l;
        *l = n;
        return _SIMPLE_LIST_OK;
    }

    n->next = NULL;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int len_simple_list(t_simple_list *l)
{
     if(!l)
        return _SIMPLE_LIST_NULL;
    if(!*l)
        return _SIMPLE_LIST_EMPTY;

    int len = 0;

    while(*l && (*l)->next)
    {
        len ++;
        l = &(*l)->next;
    }

    len ++;
    return len;
}

int get_simple_list(t_simple_list *l, void *info, size_t size, const int index)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;
    if(size <= 0)
        return _SIMPLE_LIST_SIZE;
    if(index < 0 || index >= len_simple_list(l))
        return _SIMPLE_LIST_INDEX;

    int ind = 0;

    while(*l && ind < index)
    {
        ind ++;
        l = &(*l)->next;
    }

    if(*l && ind == index)
    {
        memcpy(info,(*l)->info,size);
        return _SIMPLE_LIST_OK;
    }

    return _SIMPLE_LIST_INDEX;
}

t_node_simple_list * minor_simple_list(t_simple_list *l, t_comp comp)
{
    t_node_simple_list *min = *l;

    while(*l)
    {
        if(comp((*l)->info,min->info) < 0)
            min = *l;
        l = &(*l)->next;
    }
    return min;
}

void sort_simple_list(t_simple_list *l, size_t size, t_comp comp)
{
    if(!l)
        return;
    if(size <= 0)
        return;

    t_node_simple_list *min;

    while(*l)
    {
        min = minor_simple_list(l,comp);

        if(min != *l)
        {
            t_node_simple_list *aux = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));
            if(!aux)
                return;
            memcpy(aux->info,(*l)->info,size);
            memcpy((*l)->info,min->info,size);
            memcpy(min->info,aux->info,size);
            free(aux);
        }
        l = &(*l)->next;
    }
}

int delete_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;
    if(size <= 0)
        return _SIMPLE_LIST_SIZE;

    while(*l && comp((*l)->info,info))
        l = &(*l)->next;
    if(*l && !comp((*l)->info,info))
    {
        memcpy(info, (*l)->info,size);
        t_node_simple_list *elim = *l;
        *l = elim->next;
        free(elim);
        return _SIMPLE_LIST_OK;
    }
    return _SIMPLE_LIST_NO_DELETE;
}

int delete_all_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp)
{
    while(delete_simple_list(l,info,size,comp) == _SIMPLE_LIST_OK);
    return find_simple_list(l,info,size,comp);
}

int find_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!info)
        return _SIMPLE_LIST_INFO;
    if(size <= 0)
        return _SIMPLE_LIST_SIZE;
    while(*l && comp((*l)->info,info))
        l = &(*l)->next;

    if(*l && !comp((*l)->info,info))
    {
        memcpy(info,(*l)->info,size);
        return _SIMPLE_LIST_OK;
    }
    return _SIMPLE_LIST_NO_FIND;
}

int index_of_simple_list(t_simple_list *l, const void *info, t_comp comp)
{
    if(!l)
        return -1;
    if(!info)
        return -1;

    int index = 0;

    while(*l && comp((*l)->info,info))
    {
        index ++;
        l = &(*l)->next;
    }

    if(*l && !comp((*l)->info,info))
        return index;
    return -1;

}

void clear_simple_list(t_simple_list *l)
{
    t_node_simple_list *elim;

    while(*l)
    {
        elim = *l;
        *l = elim->next;
        free(elim->info);
        free(elim);
    }
}


int to_array_simple_list(t_simple_list *l, void * arr, const size_t size)
{
    if(!l)
        return _SIMPLE_LIST_NULL;
    if(!arr)
        return _SIMPLE_LIST_INFO;
    if(!*l)
        return _SIMPLE_LIST_EMPTY;

    int len = len_simple_list(l);
    int index = 0;
    while(index < len)
    {
        memcpy(arr + index * size, (*l)->info, size);
        index ++;
        l = &(*l)->next;
    }
    return _SIMPLE_LIST_OK;
}


