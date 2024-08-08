#ifndef TREE_SET_H_INCLUDED
#define TREE_SET_H_INCLUDED

#include "./libs/list_g.h"

#define _NULL_TREE          -10
#define _NULL_INFO          -9
#define _ERROR_SIZE         -8

#define _EMPTY_TREE         0
#define _FULL_TREE          0
#define _DUPLICATE_TREE     2
#define _OK                 1



typedef int (*t_comp)(const void *, const void *);
typedef void (*t_gra)(const void *,const int lev);
typedef void (*t_show)(const void *);


typedef struct s_tree_set {
    struct s_tree_set *l;
    struct s_tree_set *r;
    void * info;
}t_node_tree_set;

typedef t_node_tree_set * t_tree_set;


void init_tree_set (t_tree_set *t);

int is_empty_tree_set(const t_tree_set *t);

int add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp);

int height_tree_set(t_tree_set *t);
int level_info_tree_set(t_tree_set *t,void *info, t_comp comp);
int delete_tree_set(t_tree_set *t, const void *info,size_t size, t_comp comp);
int find_tree_set(t_tree_set *t, void *info, size_t size, t_comp comp);


void to_array_in_order(t_tree_set *t, void *arr, size_t size);
void to_array_pre_order(t_tree_set *t, void *arr, size_t size);
void to_array_post_order(t_tree_set *t, void *arr, size_t size);


void in_order_tree_set(t_tree_set *a, t_show show);
void pre_order_tree_set(t_tree_set *t, t_show show);
void post_order_tree_set(t_tree_set *t, t_show show);
void show_graph_tree_set(t_tree_set *t, t_tree_set *aux,t_gra dib, t_comp comp);


#endif // TREE_SET_H_INCLUDED
