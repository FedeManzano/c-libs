#include <stdio.h>
#include <stdlib.h>
#include "tree_set.h"
#include <string.h>
#include <list_g.h>


void init_tree_set (t_tree_set *t)
{
    *t = NULL;
}

int is_empty_tree_set(const t_tree_set *t)
{
    return *t == NULL;
}

int add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp)
{
    if(!t)
        return _NULL_TREE;
    if(!info)
        return _NULL_INFO;
    if(size <= 0)
        return _ERROR_SIZE;

    while(*t)
    {
        if(comp((*t)->info,info) > 0)
            t = &(*t)->l;
        else if(comp((*t)->info,info) < 0)
            t = &(*t)->r;
        else
            return 2;
    }

    t_node_tree_set  * n = (t_node_tree_set *)malloc(sizeof(t_node_tree_set));

    if(!n)
        return 0;

    n->info = malloc(size);
    if(!n->info)
        return -8;

    memcpy(n->info,info,size);

    n->l = NULL;
    n->r = NULL;
    *t = n;
    return _OK;
}

int height_tree_set(t_tree_set *t)
{
    if(!t)
        return _NULL_TREE;
    if(!*t)
        return _EMPTY_TREE;
    int l = height_tree_set(&(*t)->l) + 1;
    int r = height_tree_set(&(*t)->r) + 1;
    return l >= r ? l : r;
}


int level_info_tree_set_rec(t_tree_set *t,void *info, t_comp comp, int level)
{
    if(!t)
        return _NULL_TREE;
    if(!info)
        return _NULL_INFO;

    if(!*t)
        return _EMPTY_TREE;
    if(comp((*t)->info, info) == 0)
        return level;
    return level_info_tree_set_rec(&(*t)->l,info,comp,level + 1) +
           level_info_tree_set_rec(&(*t)->r,info,comp,level + 1);
}



int level_info_tree_set(t_tree_set *t,void *info, t_comp comp)
{
    return level_info_tree_set_rec(t,info,comp,0);
}

void in_order_tree_set(t_tree_set *t, t_show show)
{
    if(!t)
        return;

    if(!*t)
        return;

    in_order_tree_set(&(*t)->l,show);
    show((*t)->info);
    in_order_tree_set(&(*t)->r,show);
}


void pre_order_tree_set(t_tree_set *t, t_show show)
{
    if(!t)
        return;

    if(!*t)
        return;

    show((*t)->info);
    pre_order_tree_set(&(*t)->l,show);
    pre_order_tree_set(&(*t)->r,show);
}


void post_order_tree_set(t_tree_set *t, t_show show)
{
    if(!t)
        return;
    if(!*t)
        return;
    post_order_tree_set(&(*t)->l,show);
    post_order_tree_set(&(*t)->r,show);
    show((*t)->info);
}


void show_graph_tree_set(t_tree_set *t, t_tree_set *aux,t_gra dib, t_comp comp)
{
    if(!t)
        return;

    if(!*t)
        return;
    show_graph_tree_set(&(*t)->r, aux,dib, comp);
    dib( (*t)->info, level_info_tree_set( aux,(*t)->info,comp ) );
    show_graph_tree_set( &(*t)->l, aux,dib, comp );
}

t_node_tree_set ** find_node_tree_set(t_tree_set *t, const void *info, t_comp comp)
{
    if(!t)
        return NULL;
    if(!info)
        return NULL;
    while(*t)
    {
        if(comp((*t)->info,info) > 0)
            t = &(*t)->l;
        else if (comp((*t)->info,info) < 0)
            t = &(*t)->r;
        else return t;
    }

    return NULL;
}

int delete_tree_set(t_tree_set *t, const void *info,size_t size, t_comp comp)
{

    if(!t)
        return _NULL_TREE;
    if(!info)
        return _NULL_INFO;
    if(size <= 0)
        return _ERROR_SIZE;

    t_node_tree_set **aux = find_node_tree_set(t,info,comp);
    t_node_tree_set **p = aux;

    if(!aux)
        return 0;

    if(height_tree_set( &(*aux)->l) >=  height_tree_set( &(*aux)->r) )
    {
        if((*aux)->l)
        {
            aux = &(*aux)->l;
            while(aux && (*aux)->r)
                aux = &(*aux)->r;
        }
    }
    else
    {
        if((*aux)->r)
        {
            aux = &(*aux)->r;
            while(aux && (*aux)->l)
                aux = &(*aux)->l;
        }
    }

    memcpy((*p)->info,(*aux)->info, size);
    free(*aux);
    *aux = NULL;
    return _OK;
}


int find_tree_set(t_tree_set *t, void *info, size_t size, t_comp comp)
{
    if(!t)
        return _NULL_TREE;
    if(!info)
        return _NULL_INFO;
    if(size <= 0)
        return _ERROR_SIZE;

    while(*t)
    {
        if(comp((*t)->info, info) > 0)
            t = &(*t)->l;
        else if(comp((*t)->info, info) < 0)
            t = &(*t)->r;
        else
        {
            memcpy(info,(*t)->info,size);
            return 1;
        }
    }

    return _OK;
}

void to_array_in_order_rec(t_tree_set *t, t_list *l, size_t size)
{
    if(!*t)
        return;

    to_array_in_order_rec(&(*t)->l,l,size);
    add_list(l,(*t)->info,size);
    to_array_in_order_rec(&(*t)->r,l,size);
}

void to_array_in_order(t_tree_set *t, void *arr, size_t size)
{
    if(!t)
        return;
    if(!arr)
        return;
    if(size <= 0)
        return;

    t_list l;
    init_list(&l);
    to_array_in_order_rec(t,&l,sizeof(int));
    to_array_list(&l,arr,sizeof(int));
}


void to_array_pre_order_rec(t_tree_set *t, t_list *l, size_t size)
{
    if(!*t)
        return;

    add_list(l,(*t)->info,size);
    to_array_pre_order_rec(&(*t)->l,l,size);
    to_array_pre_order_rec(&(*t)->r,l,size);
}

void to_array_pre_order(t_tree_set *t, void *arr, size_t size)
{
    if(!t)
        return;
    if(!arr)
        return;
    if(size <= 0)
        return;

    t_list l;
    init_list(&l);
    to_array_pre_order_rec(t,&l,sizeof(int));
    to_array_list(&l,arr,sizeof(int));
}



void to_array_post_order_rec(t_tree_set *t, t_list *l, size_t size)
{
    if(!*t)
        return;


    to_array_post_order_rec(&(*t)->l,l,size);
    to_array_post_order_rec(&(*t)->r,l,size);
    add_list(l,(*t)->info,size);
}

void to_array_post_order(t_tree_set *t, void *arr, size_t size)
{
    if(!t)
        return;
    if(!arr)
        return;
    if(size <= 0)
        return;

    t_list l;
    init_list(&l);
    to_array_post_order_rec(t,&l,sizeof(int));
    to_array_list(&l,arr,sizeof(int));
}
