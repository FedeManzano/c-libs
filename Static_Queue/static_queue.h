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


#define _TAM_STATIC_QUEUE       100

#define _STATIC_QUEUE_EMPTY     0
#define _STATIC_QUEUE_FULL      0
#define _STATIC_QUEUE_OK        1

typedef struct
{
    void * info[_TAM_STATIC_QUEUE];
    int first;
    int last;
    int count;
}t_static_queue;


/** \brief
 * Inicializa la cola estática.
 * \param q t_static_queue* Puntero a la cola
 */
void init_static_queue(t_static_queue *q);


/** \brief
 *
 * \param q t_static_queue*
 * \return int
 */
int is_empty_static_queue(t_static_queue *q);


/** \brief
 * \param q t_static_queue*
 * \return int
 */
int is_full_static_queue(t_static_queue *q);


/** \brief
 *
 * \param q t_static_queue*
 * \param info const void*
 * \param size const size_t
 * \return int
*/
int push_static_queue(t_static_queue *q, const void *info, const size_t size);


/** \brief
 *
 * \param q t_static_queue*
 * \param info void*
 * \param size const size_t
 * \return int
 */
int pop_static_queue(t_static_queue *q, void *info, const size_t size);


/** \brief
 *
 * \param
 * \param
 * \return
 */
int first_static_queue (t_static_queue *q, void *info, const size_t size);


/** \brief
 *
 * \param
 * \param
 * \return
 */
void clear_static_queue (t_static_queue *q);



#endif // STATIC_QUEUE_H_INCLUDED
