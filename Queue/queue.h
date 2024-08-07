/**
    TDA Cola
    Cola dinámica genérica para cualquier tipo de dato
    @author Federico Manzano (https://github.com/FedeManzano)
*/

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define EMPTY_QUEUE 0
#define FULL_QUEUE  0
#define NULL_QUEUE -10
#define ERROR_INFO -9
#define OK          1

typedef struct s_nodo_queue
{
    void *info;
    struct s_nodo_queue *next;
} t_node_queue;


typedef struct
{
    t_node_queue *first;
    t_node_queue *last;
} t_queue;



/** \brief
 *  Crear la cola asignando NULL a
    los punteros first y last
 * \param q t_queue* Puntero a la cola
 * \return void
 *
 */
void init_queue(t_queue *q);



/** \brief
 * Informa si la cola es vacia.
 * \param q const t_queue* Puntero a la cola
 * \return int != 0 si no esta vacía y 0 si lo está
 *
 */
int is_empty_queue(const t_queue * q);


/** \brief
 *  Informa si la cola está llena.
 * \param q const t_queue*
 * \return int != 0 si está llena. 0 si no lo está
 */
int is_full_queue(const t_queue * q);


/** \brief
 *  Permite añadir un elemento a la cola
 * \param q t_queue* Puntero a la cola
 * \param info const void* info a cargar en la cola
 * \param size size_t tamaño del tipo de dato que están en la cola
 * \return int Si tuvi exito el ingreso 1
 *
 */
int push_queue(t_queue * q,const void * info, size_t size);



/** \brief
 *  Obtiene y retira el primer elemento de la cola.
 * \param q t_queue*
 * \param info void*
 * \param size size_t
 * \return int
 *
 */
int pop_queue(t_queue *q, void * info, size_t size);


/** \brief
 *  Obtiene el primer elemento de la cola.
 * \param q const t_queue*
 * \param info void*
 * \param size size_t
 * \return int
 *
 */
int top_queue(const t_queue *q, void *info, size_t size);



/** \brief
 *  Elimina toda la información de la cola.
 * \param q t_queue*
 * \return void
 *
 */
void clear_queue(t_queue *q);


#endif // QUEUE_H_INCLUDED
