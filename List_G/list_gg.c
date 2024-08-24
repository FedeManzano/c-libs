#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_g.h"


void init_list(t_list * l)
{
    *l = NULL;
}

int is_empty_list(const t_list *l)
{
    return *l == NULL;
}

int is_full_list(const t_list * l)
{
    return !malloc(sizeof(t_node_list));
}

int add_list_o(t_list *l,const void *info,const size_t tam, t_comp comp)
{
    if(!l)
        return LIST_NULL;
    if(!info)
        return ERROR_INFO;

    t_node_list * n = (t_node_list *)malloc(sizeof(t_node_list));

    if(!n)
        return FULL_MEMORY;
    n->info = malloc(tam);
    memcpy(n->info,info,tam);

    if(!*l)
    {
        n->back = NULL;
        n->next = NULL;
        *l = n;
        return OK;
    }

    t_node_list *back = *l;
    t_node_list *next = *l;

    while(next && comp(next->info,info) < 0)
    {
        back = next;
        next = next->next;
    }

    while(back && comp(back->info,info) > 0)
    {
        next = back;
        back = back->back;
    }

    if(next && !comp(next->info,info))
    {
        return ELE_DUPLICATE;
    }

    if(back && !comp(back->info,info))
    {
        return ELE_DUPLICATE;
    }

    n->back = back;
    n->next = next;

    if(n && n->back)
        n->back->next = n;
    else if(n && n->next)
        n->next->back = n;
    *l = n;

    return OK;
}

int try_add_list_o(t_list *l,const void *info,const size_t tam, t_comp comp)
{
    if(!l)
        return LIST_NULL;
    if(!info)
        return ERROR_INFO;

    t_node_list * n = (t_node_list *)malloc(sizeof(t_node_list));

    if(!n)
        return FULL_MEMORY;
    n->info = malloc(tam);
    memcpy(n->info,info,tam);

    if(!*l)
    {
        n->back = NULL;
        n->next = NULL;
        *l = n;
        return OK;
    }

    t_node_list *back = *l;
    t_node_list *next = *l;

    while(next && comp(next->info,info) < 0)
    {
        back = next;
        next = next->next;
    }

    while(back && comp(back->info,info) > 0)
    {
        next = back;
        back = back->back;
    }

    if(next && !comp(next->info,info))
    {
        memcpy(next->info,info,tam);
        return ELE_DUPLICATE;
    }

    if(back && !comp(back->info,info))
    {
        memcpy(back->info,info,tam);
        return ELE_DUPLICATE;
    }

    n->back = back;
    n->next = next;

    if(n && n->back)
        n->back->next = n;
    else if(n && n->next)
        n->next->back = n;
    *l = n;

    return OK;
}

int add_first_list(t_list *l, const void *info, const size_t tam)
{
    if(!l)
        return LIST_NULL;
    if(!info)
        return ERROR_INFO;

    while(*l && (*l)->back)
        l = &(*l)->back;

    t_node_list * n = (t_node_list *)malloc(sizeof(t_node_list));
    if(!n)
        return FULL_MEMORY;

    n->info = malloc(tam);
    memcpy(n->info,info,tam);
    n->back = NULL;
    n->next = *l;
    *l = n;

    return OK;
}

int add_list(t_list *l, const void *info, const size_t tam)
{
    if(!l)
        return LIST_NULL;
    if(!info)
        return ERROR_INFO;


    t_node_list * n = (t_node_list *)malloc(sizeof(t_node_list));
    if(!n)
        return FULL_MEMORY;
    n->info = malloc(tam);

    if(!n->info)
        return FULL_MEMORY;
    memcpy(n->info,info,tam);

    if(!*l)
    {
        n->back = NULL;
        n->next = NULL;
        *l = n;
        return 1;
    }
    while(*l && (*l)->next)
        l = &(*l)->next;
    n->next = NULL;
    n->back = *l;
    (*l)->next = n;
    return 1;
}

int get_key_list(t_list *l, void *info,const size_t tam, t_comp comp)
{
    if(!l)
        return LIST_NULL;
    if(!*l)
        return LIST_EMPTY;
    if(!info)
        return ERROR_INFO;

    t_node_list *next = *l;
    t_node_list *back = *l;

    while(next && comp(next->info, info))
        next = next->next;

    if(next && !comp(next->info, info))
    {
        memcpy(info,next->info,tam);
        return OK;
    }

    while(back && comp(back->info, info))
        back = back->back;

    if(back && !comp(back->info, info))
    {
        memcpy(info,back->info,tam);
        return OK;
    }

    return ELE_NO_FIND;
}

int get_key_last_list(t_list *l, void *info,const size_t tam, t_comp comp)
{
    if(!l)
        return LIST_NULL;
    if(!*l)
        return LIST_EMPTY;
    if(!info)
        return ERROR_INFO;

    t_node_list * bus = *l;

    while(bus && bus->next)
        bus = bus->next;
    while(bus && comp(bus->info,info))
        bus = bus->back;
    if(bus && !comp(bus->info,info))
    {
        memcpy(info,bus->info,tam);
        return OK;
    }
    return ELE_NO_FIND;
}

int len_list(t_list *l)
{
    if(!l)
        return LIST_NULL;
    if(!*l)
        return LIST_EMPTY;
    int len = 0;

    while(*l && (*l)->back)
        l = &(*l)->back;

    while(*l && (*l)->next)
    {
        len ++;
        l = &(*l)->next;
    }
    len ++;
    return len;
}

void * get_info_list(t_list *l,void *info,const size_t tam,const int index)
{
    if(!l || !*l )
        return NULL;
    if(index < 0 && index >= len_list(l))
        return NULL;

    t_node_list *aux = *l;

    while(aux && aux->back)
        aux = aux->back;
    int ind = 0;

    while(aux && aux->next && ind < index)
    {
        aux = aux->next;
        ind ++;
    }
    memcpy(info, aux->info,tam);
    return info;
}

int delete_list(t_list *l, void *info,const size_t tam, t_comp comp)
{
    if(!l)
        return LIST_NULL;
    if(!*l)
        return LIST_EMPTY;
    if(!info)
        return ERROR_INFO;

    t_node_list *elim = *l;

    while(elim && elim->back)
        elim = elim->back;

    while(elim && comp(elim->info, info) != 0 )
        elim = elim->next;

    int lin = len_list(l);

    if(elim && !comp(elim->info, info))
    {
        memcpy(info, elim->info,tam);

        if(elim->back)
            elim->back->next = elim->next;
        if(elim->next)
            elim->next->back = elim->back;

        if(elim->next)
            *l = elim->next;
        else if(elim->back)
            *l = elim->back;

        free((elim));
        if(lin == 1)
            *l = NULL;
        return OK;
    }

    return ELE_NO_FIND;
}

int delete_all_list(t_list *l, void *info,const size_t tam, t_comp comp)
{
    while(delete_list(l,info,tam,comp));
    return !get_key_list(l,info,tam,comp) ? OK : ELE_NO_FIND;
}

t_node_list * minor_list(t_list *l, const int tam,t_comp comp)
{
    t_node_list *min = *l;
    while(*l)
    {
        if(comp((*l)->info,min->info) < 0)
            min = *l;
        l = &(*l)->next;
    }
    return min;
}

void sort_list(t_list *l,const size_t tam, t_comp comp)
{
    if(!l)
        return;
    if(!*l)
        return;

    t_node_list *la = *l;
    t_node_list *min = la;



    while(la)
    {
        min = minor_list(&la,tam,comp);
        if(!min)
            return;
        if(comp(la->info,min->info))
        {
            void * a = malloc(tam);
            memcpy(a,la->info,tam);
            memcpy(la->info,min->info,tam);
            memcpy(min->info,a,tam);
            free(a);
        }
        la = la->next;
    }

}

t_node_list * first_list(t_list *l)
{
    return *l;
}

void sort_selection_list(t_list *l,const size_t tam, t_comp comp)
{
    if(!l)
        return;
    if(!*l)
        return;
    t_node_list *act = *l;
    t_node_list *min = *l;

    while(act)
    {
        min = minor_list(l,tam,comp);

        if(act != min)
        {
            if(act->next != min)
            {
                if(act->back)
                    act->back->next = min;
                if(act->next)
                    act->next->back = min;
                if(min->next)
                    min->next->back = act;
                if(min->back)
                    min->back->next = act;
                t_node_list *aux = min->next;
                min->next = act->next;
                act->next = aux;
                aux = act->back;
                act->back = min->back;
                min->back = aux;
            }
            else
            {
                act->next = min->next;
                if(min->next)
                    min->next->back = act;
                if(act->back)
                    act->back->next = min;
                min->back = act->back;
                act->back = min;
                min->next = act;
            }
        }
        act = min->next;
        l = &min->next;
    }
}

int insert_list(t_list *l,const void * info,const size_t tam, const int index)
{
    if(!l)
        return LIST_NULL;
    if(!info)
        return ERROR_INFO;
    if(index < 0 )
        return INDEX_BOUNDS;

    int ind = 0;

    while(*l && (*l)->back)
        l = &(*l)->back;

    t_node_list * n = (t_node_list *)malloc(sizeof(t_node_list));
    if(!n) return FULL_MEMORY;

    n->info = malloc(tam);
    if(!n->info)
        return FULL_MEMORY;

    memcpy(n->info,info,tam);

    if(index >= 0 && !*l)
        return add_first_list(l,info,tam);

    t_node_list *aux = *l;

    if(index >= len_list(l))
    {
        while(aux && aux->next)
            aux = aux->next;
        n->back = aux;
        n->next = NULL;
        aux->next = n;
        return OK;
    }

    if(index == 0)
    {
        n->next = aux;
        n->back = NULL;
        aux->back = n;
        return OK;
    }

    while(aux && ind < index)
    {
        aux = aux->next;
        ind ++;
    }
    n->next = aux;
    n->back = aux->back;
    if(aux->back)
        aux->back->next = n;
    aux->back = n;
    return OK;
}

int insert_range_list(t_list *l,const void * arr,const int ce,const size_t tam, int index)
{
    if(!l)
        return LIST_NULL;
    if(!arr)
        return ERROR_INFO;
    if(index < 0 )
        return INDEX_BOUNDS;

    int nro = 0;
    int res;
    for(int i = 0; i < ce; i++)
    {
        res = insert_list(l,arr + nro * tam,tam,index);
        index ++;
        nro ++;
    }
    return res;
}

void clear_list(t_list *l)
{
    if(!l)
        return;
    t_node_list * elim = *l;

    while(elim && elim->back)
        elim = elim->back;

    while(*l)
    {
        *l = elim->next;
        free(elim->info);
        free(elim);
        elim = *l;
    }
    *l = NULL;
}

int to_array_list(t_list *l, void *arr,const size_t tam)
{
    if(!l)
        return LIST_NULL;
    if(!*l)
        return LIST_EMPTY;
    if(!arr)
        return ERROR_INFO;

    while(*l && (*l)->back)
        l = &(*l)->back;
    int i = 0;
    while(*l && (*l)->next)
    {
        memcpy(arr + i * tam,(*l)->info,tam);
        l = &(*l)->next;
        i ++;
    }
    memcpy(arr + i * tam,(*l)->info,tam);
    return OK;
}

t_list filter_list(t_list *l, const size_t size, t_filter filter)
{
    if(!*l)
        return NULL;
    if(size)
    while(*l && (*l)->back)
        l = &(*l)->back;

    t_list lret = (t_list)malloc(sizeof(t_list));
    init_list(&lret);

    while(*l)
    {
        if(filter((*l)->info))
            if(!is_full_list(&lret))
                add_list(&lret,(*l)->info,size);
        l = &(*l)->next;
    }
    return lret;
}

int index_of_list(t_list *l, const void *info,const int tam, t_comp comp)
{
    if(!l || !*l || !info)
        return -1;

    int ind = 0;

    while(*l && (*l)->back)
        l = &(*l)->back;

    while(*l && comp((*l)->info,info) != 0)
    {
        ind ++;
        l = &(*l)->next;
    }

    if(*l && !comp((*l)->info,info))
    {
        return ind;
    }
    return -1;
}



