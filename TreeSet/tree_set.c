#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_set.h"



void init_tree_set (t_tree_set *t)
{
    *t = NULL;
}

int is_empty_tree_set(const t_tree_set *t)
{
    return *t == NULL;
}

int is_full_tree_set(const t_tree_set *t)
{
    return !malloc(sizeof(t_node_tree_set));
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
            return _DUPLICATE_TREE;
    }

    t_node_tree_set  * n = (t_node_tree_set *)malloc(sizeof(t_node_tree_set));

    if(!n)
        return _FULL_TREE;

    n->info = malloc(size);
    if(!n->info)
        return _FULL_TREE;

    memcpy(n->info,info,size);

    n->l = NULL;
    n->r = NULL;
    *t = n;
    return _OK;
}

int try_add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp)
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
        else {
            memcpy((*t)->info, info,size);
            return _DUPLICATE_TREE;
        }
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

int level_tree_set(t_tree_set *t)
{
    int h = height_tree_set(t);
    return h > 0 ? h - 1 : h;
}

void show_level_tree_set(t_tree_set *t, int level, t_show show)
{
    if(!t)
        return;
    if(!*t)
        return;
    if(level < 0)
        return;
    if(!level)
        show((*t)->info);
    show_level_tree_set(&(*t)->l,level - 1, show);
    show_level_tree_set(&(*t)->r,level - 1, show);
}

void amplitude_tree_set(t_tree_set *t, t_show show)
{
    int levels = level_tree_set(t);
    for(int i = 0; i <= levels; i ++ )
        show_level_tree_set(t,i,show);
}

int level_info_tree_set_rec(t_tree_set *t,void *info, t_comp comp, int level)
{
    if(!*t)
        return _EMPTY_TREE;
    if(comp((*t)->info, info) == 0)
        return level;
    return level_info_tree_set_rec(&(*t)->l,info,comp,level + 1) +
           level_info_tree_set_rec(&(*t)->r,info,comp,level + 1);
}

int level_info_tree_set(t_tree_set *t,void *info, t_comp comp)
{
    if(!t)
        return _NULL_TREE;
    if(!info)
        return _NULL_INFO;
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

void show_graph_tree_set_rec(t_tree_set *t, t_tree_set *aux,t_gra dib, t_comp comp)
{
    if(!t)
        return;

    if(!*t)
        return;
    show_graph_tree_set_rec(&(*t)->r, aux,dib, comp);
    dib( (*t)->info, level_info_tree_set( aux,(*t)->info,comp ) );
    show_graph_tree_set_rec( &(*t)->l, aux,dib, comp );
}

void show_graph_tree_set(t_tree_set *t,t_gra dib, t_comp comp)
{
    show_graph_tree_set_rec(t,t,dib,comp);
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
            return _OK;
        }
    }
    return _NO_FIND_ELE;
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
    to_array_in_order_rec(t,&l,size);
    to_array_list(&l,arr,size);
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
    to_array_pre_order_rec(t,&l,size);
    to_array_list(&l,arr,size);
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
    to_array_post_order_rec(t,&l,size);
    to_array_list(&l,arr,size);
}

int count_tree_set(const t_tree_set *t)
{
    if(!t)
        return _NULL_TREE;
    if(!*t)
        return _EMPTY_TREE;
    return 1 + count_tree_set(&(*t)->l) + count_tree_set(&(*t)->r);
}

void clear_tree_set(t_tree_set *t)
{
    if(!t) return;
    if(!*t) return;
    clear_tree_set(&(*t)->l);
    clear_tree_set(&(*t)->r);
    free(*t);
    *t = NULL;
}

int count_leaf_tree_set(t_tree_set *t)
{
    if(!t)
        return _NULL_TREE;
    if(!*t)
        return _EMPTY_TREE;

    if(_IS_TREE_LEAF(*t))
        return 1 + count_leaf_tree_set(&(*t)->l) + count_leaf_tree_set(&(*t)->r);
    return count_leaf_tree_set(&(*t)->l) + count_leaf_tree_set(&(*t)->r);
}

void delete_left_tree_set(t_tree_set *t)
{
    if(!t)
        return;
    if(!*t)
        return;

    if(!_IS_TREE_LEAF(*t))
    {
        delete_left_tree_set(&(*t)->l);
        delete_left_tree_set(&(*t)->r);
    } else
    {
        free(*t);
        *t = NULL;
    }
}

void show_leaf_tree_set(t_tree_set *t, t_show show)
{
    if(!t)
        return;
    if(!*t)
        return;
    if(_IS_TREE_LEAF(*t))
        show((*t)->info);
    show_leaf_tree_set(&(*t)->l,show);
    show_leaf_tree_set(&(*t)->r,show);
}

void file_to_tree_set_rec(t_tree_set *t, FILE **fi,const size_t size_tree,const size_t size_file, long inicio, long end, t_comp comp,t_read read)
{
	long med = ( inicio + end ) / 2;

	void * info_file = malloc(size_file);
	void * info_tree = malloc(size_tree);

	if(!info_file || !info_tree)
        return;

    fseek(*fi,size_file * med,SEEK_CUR);
    fread(info_file,size_file, 1, *fi);
	fseek(*fi,0L,SEEK_SET);

	read(info_tree, info_file, med);

	add_tree_set(t,info_tree,size_tree,comp);

	free(info_file);
	free(info_tree);

	if(inicio < med)
		file_to_tree_set_rec(t, fi,size_tree,size_file, inicio , med - 1,comp, read);
	if(end > med)
		file_to_tree_set_rec(t, fi,size_tree,size_file, med + 1, end, comp, read);
}

void  file_to_tree_set(t_tree_set *t, FILE **arch, const size_t size_tree, const size_t size_file, t_comp comp, t_read read)
{
    if(!t || !arch || !*arch || size_file <= 0 || size_tree <= 0) {
        return;
    }

	fseek(*arch, 0L, SEEK_END);
	long regs = ftell(*arch) / size_file;
	fseek(*arch, 0L, SEEK_SET);
    file_to_tree_set_rec(t,arch,size_tree,size_file, 0,regs-1, comp, read);
}

int update_tree_set(t_tree_set *t,const void *info, t_comp comp, t_update update)
{
    if(!t)
        return _NULL_TREE;
    if(!*t)
        return _EMPTY_TREE;
    if(!comp((*t)->info,info))
    {
        update((*t)->info,info);
        return _OK;
    }
    return update_tree_set(&(*t)->l,info,comp,update) +
           update_tree_set(&(*t)->r,info,comp,update);
}
