#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define EMPTY_QUEUE 0
#define FULL_QUEUE  0
#define NULL_QUEUE -10
#define ERROR_INFO -9
#define OK          1

typedef struct s_nodo_queue  {
    void *info;
    struct s_nodo_queue *next;
}t_node_queue;


typedef struct {
     t_node_queue *first;
     t_node_queue *last;
}t_queue;



void init_queue(t_queue *q);

int is_empty_queue(const t_queue * q);

int is_full_queue(const t_queue * q);

int push_queue(t_queue * q,const void * info, size_t size);

int pop_queue(t_queue *q, void * info, size_t size);

int top_queue(const t_queue *q, void *info, size_t size);

void clear_queue(t_queue *q);


#endif // QUEUE_H_INCLUDED
