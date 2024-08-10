
/**
*   TDA Pila
*
*   Pila genérica para almacenar cualquier tipo de dato.
*   El puntero a la información, en la estructura, es de tipo
*   (void *).
*
*   ADV: Queda suje a la responsabilidad del usuario que no se ingresen varios
*   tipos de datos al mismo tiempo en la pila. Si esto sucede el funcionamiento
*   dará errores.
*
*   @author Federico Mazano (https://github.com/FedeManzano)
*/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#define FULL_STACK  0
#define EMPTY_STACK 0
#define NULL_STACK -10
#define NULL_INFO   -9
#define OK           1



typedef struct s_node{
    struct s_node *next;
    void * info;
}t_node_stack;

typedef t_node_stack * t_stack;


/** \brief
 * Permite crear la pila, poniento el puntero de pila en nulo.
 * \param s t_stack* Puntero de pila
 * \return void
 *
 */
void init_stack(t_stack *s);


/** \brief
 *  Permite saber si una pila esta vacía o no.
 * \param s const t_stack* Puntero de pila
 * \return int != si esta vacía 0 si no lo está
 *
 */
int is_empty_stack(const t_stack *s);


/** \brief
 *  Permite saber si la pila está llena (si hay o no memoria en el ordenador).
 * \param s const t_stack* Puntero de pila
 * \return int != si está llena, 0 si no lo está.
 *
 */
int is_full_stack(const t_stack *s);



/** \brief
 * Permite añadir un elemento a la pila.
 * \param s t_stack* Puntero de pila
 * \param info const void* Info que se va a cargar en la pila
 * \param size const size_t Tamaño del tipo de dato que se va a guardar
 * \return int Si salió todo bien retorna 1, -9,-10,0 en otros casos.
 *
 */
int push_stack(t_stack *s, const void *info, const size_t size);



/** \brief
 * Permite sacar el primer elemento de la pila.
 * Lo carga en la estructura y luego lo elimina de la pila.
 * \param s t_stack* Puntero de pila
 * \param info void* Puntero sonde se va a cargar la info.
 * \param size size_t Tamaño del tipo de dato guardado en la pila.
 * \return int 1 Si pudo extraer el elemento, -10,-9,0 si no pudo hacerlo.
 *
 */
int pop_stack(t_stack *s, void * info, size_t size);



/** \brief
 * Permite ver el primer elemento de la pila. Este no se elimina,
 * pero es cargado en la estructura a través del puntero *info.
 * \param info void* Puntero sonde se va a cargar la info.
 * \param size size_t Tamaño del tipo de dato guardado en la pila.
 * \return int 1 Si pudo extraer el elemento, -10,-9,0 si no pudo hacerlo.
 *
 */
int top_stack(const t_stack *s, void *info, size_t size);



/** \brief
 * Elimina todos los elementos de la pila.
 * \param s t_stack* Puntero de pila
 * \return void
 */
void clear_stack(t_stack *s);


#endif // STACK_H_INCLUDED
