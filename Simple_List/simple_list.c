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
    if(size <= 0)
        return _SIMPLE_LIST_SIZE;

    t_node_simple_list *n = (t_node_simple_list *)malloc(sizeof(t_node_simple_list));

    if(!n)
        return _SIMPLE_LIST_FULL;

    n->info = malloc(size);

    if(!n->info)
        return _SIMPLE_LIST_FULL;


    memcpy(n->info, info,size);

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;

    n->next = *l;
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

    n->next = *l;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int try_add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp)
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

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;


    if(*l && !comp((*l)->info,info))
    {
        free(n->info);
        free(n);
        memcpy((*l)->info, info,size);
        return _SIMPLE_LIST_DUP;
    }

    n->next = *l;
    *l = n;
    return _SIMPLE_LIST_OK;
}

int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update)
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

    while(*l && comp((*l)->info,info) < 0)
        l = &(*l)->next;


    if(*l && !comp((*l)->info,info))
    {
        free(n->info);
        free(n);
        update((*l)->info, info);
        return _SIMPLE_LIST_DUP;
    }

    n->next = *l;
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
            aux->info = malloc(size);
            memcpy(aux->info,(*l)->info,size);
            memcpy((*l)->info,min->info,size);
            memcpy(min->info,aux->info,size);
            free(aux->info);
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

t_simple_list filter_simple_list(t_simple_list *l, size_t size, t_filter filter)
{
    if(!l)
        return NULL;
    if(!*l)
        return NULL;
    if(size <= 0)
        return NULL;

    t_simple_list lret = (t_simple_list)malloc(sizeof(t_simple_list));
    init_simple_list(&lret);

    while(*l)
    {
        if(filter((*l)->info))
            if(!is_full_simple_list(&lret))
                add_simple_list(&lret,(*l)->info,size);
        l = &(*l)->next;
    }

    return lret;
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

t_simple_list sub_simple_list(t_simple_list *l, const size_t size, const int start, const int end)
{
    if(!l)
        return NULL;
    if(!*l)
        return NULL;

    if(size <= 0)
        return NULL;

    if(start < 0 || end < 0)
        return NULL;

    if(start > end)
        return NULL;

    t_simple_list ln = (t_simple_list)malloc(sizeof(t_simple_list));
    init_simple_list(&ln);

    void *info = malloc(size);
    for(int i = start; i <= end; i ++)
    {
        if(get_simple_list(l,info,size,i) != _SIMPLE_LIST_INDEX)
            add_simple_list(&ln,info,size);
    }

    return ln;
}

int equals_simple_list(t_simple_list *l1, t_simple_list *l2, t_comp comp)
{
    if(!l1 && !l2)
        return _SIMPLE_LIST_EQUALS;
    if(l1 && !l2)
        return _SIMPLE_LIST_NO_EQUALS;
    if(!l1 && l2)
        return _SIMPLE_LIST_NO_EQUALS;
    if(!*l1 && !*l2)
        return _SIMPLE_LIST_EQUALS;
    if(*l1 && !*l2)
        return _SIMPLE_LIST_NO_EQUALS;
    if(!*l1 && *l2)
        return _SIMPLE_LIST_NO_EQUALS;
    if(len_simple_list(l1) != len_simple_list(l2))
        return _SIMPLE_LIST_NO_EQUALS;

    while(*l1 && *l2)
    {
        if(comp((*l1)->info,(*l2)->info))
            return _SIMPLE_LIST_NO_EQUALS;
        l1 = &(*l1)->next;
        l2 = &(*l2)->next;
    }

    if(!*l1 && !*l2)
        return _SIMPLE_LIST_EQUALS;
    return _SIMPLE_LIST_NO_EQUALS;
}

t_simple_list intersection_simple_list(t_simple_list *l1, t_simple_list *l2,const size_t size, t_comp comp)
{
    t_simple_list ret = (t_simple_list)malloc(sizeof(t_simple_list));
    if(!ret)
        return ret;
    init_simple_list(&ret);

    if(!l1 || !l2)
        return ret;
    if(!*l1 || !*l2)
        return ret;

    if(size <= 0)
        return ret;

    while(*l2)
    {
        if(index_of_simple_list(l1,(*l2)->info,comp) != -1
           && index_of_simple_list(&ret,(*l2)->info,comp) == -1)
            if(!is_full_simple_list(&ret))
                add_simple_list(&ret,(*l2)->info,size);
        l2 = &(*l2)->next;
    }
    return ret;
}

t_simple_list subtract_simple_list(t_simple_list *l1, t_simple_list *l2, const size_t size, t_comp comp)
{
    t_simple_list ret = (t_simple_list)malloc(sizeof(t_simple_list));

    if(!ret)
        return ret;


    init_simple_list(&ret);

    if(!l1 || !l2)
        return ret;
    if(!*l1 || !*l2)
        return ret;

    if(size <= 0)
        return ret;

    while(*l1)
    {
        if(index_of_simple_list(l2, (*l1)->info,comp) == -1
           && index_of_simple_list(&ret, (*l1)->info,comp) == -1)
                if(!is_full_simple_list(&ret))
                    add_simple_list(&ret,(*l1)->info,size);
        l1 = &(*l1)->next;
    }
    return ret;
}

t_simple_list union_simple_list(t_simple_list *l1, t_simple_list *l2, const size_t size, t_comp comp)
{
    t_simple_list ret = (t_simple_list)malloc(sizeof(t_simple_list));

    if(!ret)
        return ret;
    init_simple_list(&ret);

    if(!l1 || !l2)
        return ret;
    if(!*l1 || !*l2)
        return ret;

    if(size <= 0)
        return ret;

    while(*l1 || *l2)
    {
        if(index_of_simple_list(&ret,(*l1)->info,comp) == -1)
            if(!is_full_simple_list(&ret))
                add_first_simple_list(&ret,(*l1)->info,size);
        if(index_of_simple_list(&ret,(*l2)->info,comp) == -1)
            if(!is_full_simple_list(&ret))
                add_first_simple_list(&ret,(*l2)->info,size);
        if(*l1)
            l1 = &(*l1)->next;
        if(*l2)
            l2 = &(*l2)->next;
    }
    return ret;
}

int file_to_simple_list(t_simple_list *l, const char *path, const size_t size)
{
    FILE *file = fopen(path,"rb");
    if(!file)
        return 0;

    void *aux = malloc(size);
    if(!aux)
        return 0;

    clear_simple_list(l);
    fread(aux,size,1,file);
    while(!feof(file))
    {
        add_simple_list(l,aux,size);
        fread(aux,size,1,file);
    }
    fclose(file);
    return 1;
}

int simple_list_to_file(t_simple_list *l, const char * path, const size_t size)
{
    if(!l)
        return 0;
    if(!*l)
        return 0;
    FILE * file = fopen(path, "wb");
    if(!file)
        return 0;
    void *info = malloc(size);
    if(!info)
        return 0;
    int len = len_simple_list(l);

    for(int i = 0; i < len; i ++)
    {
        get_simple_list(l,info,size,i);
        fwrite(info,size,1,file);
    }
    fclose(file);
    return 1;
}
