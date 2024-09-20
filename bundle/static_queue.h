/**
    TDA Cola Estática

    Funciones:
    void init_static_queue(t_static_queue *q);
    int is_empty_static_queue(t_static_queue *q);
    int is_full_static_queue(t_static_queue *q);
    int push_static_queue(t_static_queue *q, const void *info, const size_t size);
    int pop_static_queue(t_static_queue *q, void *info, const size_t size);
    int first_static_queue (t_static_queue *q, void *info, const size_t size);
    void clear_static_queue (t_static_queue *q);
*/

#ifndef STATIC_QUEUE_H_INCLUDED
#define STATIC_QUEUE_H_INCLUDED


#define _TAM_STATIC_QUEUE 10


typedef struct
{
    void * info[_TAM_STATIC_QUEUE];
    int first;
    int last;
    int count;
}t_static_queue;


void init_static_queue(t_static_queue *q);
int is_empty_static_queue(t_static_queue *q);
int is_full_static_queue(t_static_queue *q);
int push_static_queue(t_static_queue *q, const void *info, const size_t size);
int pop_static_queue(t_static_queue *q, void *info, const size_t size);
int first_static_queue (t_static_queue *q, void *info, const size_t size);
void clear_static_queue (t_static_queue *q);



#endif // STATIC_QUEUE_H_INCLUDED
