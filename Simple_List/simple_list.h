#ifndef SIMPLE_LIST_H_INCLUDED
#define SIMPLE_LIST_H_INCLUDED


#define _SIMPLE_LIST_NULL -10
#define _SIMPLE_LIST_INFO -9
#define _SIMPLE_LIST_SIZE -8
#define _SIMPLE_LIST_INDEX -7

#define _SIMPLE_LIST_EMPTY 0
#define _SIMPLE_LIST_FULL  0
#define _SIMPLE_LIST_DUP 2
#define _SIMPLE_LIST_NO_INSERT -1
#define _SIMPLE_LIST_NO_DELETE -1
#define _SIMPLE_LIST_NO_FIND -1
#define _SIMPLE_LIST_OK 1


typedef int (*t_comp)(const void *,const void *);
typedef void (*t_update)(void *info_list, void *info_update);

typedef struct s_node_simple_list
{
    struct s_node_simple_list * next;
    void * info;
} t_node_simple_list;


typedef t_node_simple_list * t_simple_list;



void init_simple_list(t_simple_list *l);
int is_empty_simple_list(t_simple_list *l);
int is_full_simple_list(t_simple_list *l);
int add_simple_list(t_simple_list *l, const void *info, const size_t size);
int len_simple_list(t_simple_list *l);
int get_simple_list(t_simple_list *l, void *info, size_t size, const int index);
int add_simple_list_in_order(t_simple_list *l, const void *info, const size_t size, t_comp comp);
int add_first_simple_list(t_simple_list *l, const void *info, const size_t size);
int add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);
int try_add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);
int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update, const void *info_update);
int insert_simple_list(t_simple_list *l,const void *info, size_t size,const int index);
int insert_range_simple_list(t_simple_list *l,const void *arr, size_t size,const int ce, int index);
void sort_simple_list(t_simple_list *l, size_t size, t_comp comp);
int delete_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
int delete_all_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
int find_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
int index_of_simple_list(t_simple_list *l, const void *info, t_comp comp);
void clear_simple_list(t_simple_list *l);

#endif // SIMPLE_LIST_H_INCLUDED
