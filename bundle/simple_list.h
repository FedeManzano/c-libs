
/**
    TDA Lista Simplemente Enlazada

    Funciones:

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
    int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update);
    int insert_simple_list(t_simple_list *l,const void *info, size_t size,const int index);
    int insert_range_simple_list(t_simple_list *l,const void *arr, size_t size,const int ce, int index);
    void sort_simple_list(t_simple_list *l, size_t size, t_comp comp);
    int delete_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
    int delete_all_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
    int find_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
    int index_of_simple_list(t_simple_list *l, const void *info, t_comp comp);
    t_simple_list filter_simple_list(t_simple_list *l, size_t size, t_filter filter);
    void clear_simple_list(t_simple_list *l);
    int to_array_simple_list(t_simple_list *l, void * arr, const size_t size);


    ADV:

    Los tipos de datos agregados a este TDA son gen�ricos,
    por lo tanto, en cada lista creada es responsabilidad del
    programador almacer el mismo tipo de dato.

    @author Federico Manzano (https://github.com/FedeManzano)
*/

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


/** \brief
    Puntero a funci�n de comparaci�n.
 */
typedef int (*t_comp)(const void *,const void *);

typedef int (*t_filter)(const void *);

/** \brief
    Puntero a funci�n que permite actualizar uno de los
    elementos que se encuentra en la lista.
 */
typedef void (*t_update)(void *info_list, const void *info_update);


typedef struct s_node_simple_list
{
    struct s_node_simple_list * next;
    void * info;
} t_node_simple_list;


typedef t_node_simple_list * t_simple_list;



/** \brief
 *  Crea la lista asignando el *lista a NULL
 * \param l t_simple_list* Puntero a la lista
 * \return void
 */
void init_simple_list(t_simple_list *l);


/** \brief
 *  Permite conocer si la lista est� vac�a o
    tiene elementos.
 * \param l t_simple_list* Puntero a la lista
 * \return int Si est� vac�a retorna != 0.
 */
int is_empty_simple_list(t_simple_list *l);


/** \brief
 * Permite conocer si hay espacio en la memoria para almacenar
 * un elemento nuevo.
 * \param l t_simple_list* Puntero a la lista
 * \return int Distinto de 0 si est� llena. Caso contrario hay espacio.
 *
 */
int is_full_simple_list(t_simple_list *l);


/** \brief
 *  Agrega un elemento al final de la lista.
 * \param  l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la informaci�n a guardar.
 * \param size const size_t Tama�o de la informaci�n a guardar.
 * \return int 1 Si logr� agregar la info. != 1 si hubo alg�n problema.
 */
int add_simple_list(t_simple_list *l, const void *info, const size_t size);


/** \brief
 * Devuelve la cantidad de elementos de la lista.
 * \param  l t_simple_list* Puntero a la lista
 * \return int Longitud de la lista (Cantidad de elementos).
 *
 */
int len_simple_list(t_simple_list *l);


/** \brief
 * Permite acceder el elemento de la lista de index pasado por par�metro.
 * \param l t_simple_list* Puntero a la lista
 * \param info void* Puntero donde se cargar� la info solicitada.
 * \param size size_t Tama�o de la informaci�n que se solicita.
 * \param index const int indice del cual se quiere acceder a la info.
 * \return int 1 Si encontro la informaci�n. != 1 si no la encontr�.
 *
 */
int get_simple_list(t_simple_list *l, void *info, size_t size, const int index);


/** \brief
 * Agrega un elemento a la lista de manera ordenada.
 * Utilizando la funci�n de comparaci�n recibida por par�metro.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Info que se desea guardar.
 * \param size const size_t Tama�o de la informaci�n que se desea guardar.
 * \param comp t_comp Puntero a funci�n de comparaci�n
 * \return int 1 Si la pudo guardar. != 1 si hubo problemas.
 *
 */
int add_simple_list_in_order(t_simple_list *l, const void *info, const size_t size, t_comp comp);


/** \brief
 * A�ade un elemento a la lista al comienzo de la misma.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info que se desea guardar.
 * \param size const size_t Tama�o de la info a guardar.
 * \return int 1 si la pudo guardar.
 */
int add_first_simple_list(t_simple_list *l, const void *info, const size_t size);



/** \brief
 * Guarda un elemento en la lista de manera ordenada.
 * Esta funci�n no permite duplicados. Si el elemento a ingresar
 * ya se encontraba en la lista, este de descarta.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size const size_t Tama�o de la info a guardar.
 * \param comp t_comp Puntero a la funci�n de comparaci�n.
 * \return int 1 si pudo agregar la info.
 */
int add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);


/** \brief
 * Guarda un elemento en la lista de manera ordenada.
 * Esta funci�n no permite duplicados. Si el elemento a ingresar
 * ya se encontraba en la lista, esta funci�n lo reemplaza con el nuevo elemento duplicado.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size const size_t Tama�o de la info a guardar.
 * \param comp t_comp Puntero a la funci�n de comparaci�n.
 * \return int 1 si pudo agregar la info.
 */
int try_add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);



/** \brief
 * Esta funci�n permite agregar un elemento de forma ordenada.
 * Si el elemento ya se encuentra en la lista, esta funci�n permite la actualizaci�n de
 * la informaci�n que recide en la lista con la nueva informaci�n que viene por par�metro.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size const size_t Tama�o de la info a guardar.
 * \param comp t_comp Puntero a la funci�n de comparaci�n.
 * \param update t_update Puntero a funci�n que permite la actualizaci�n de la info de la lista.
 * \return int 1 si pudo almacenar el nodo. 2 si lo actualiz�. un valor diferente es por error.
 */
int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update);



/** \brief
 * Inserta un elemento en un index recibido por par�metro de la funci�n.
 * Si el indice donde se quiere ingresar el elemento es mayor que la cantidad
 * de elementos de la lista, el mismo se inserta al final de la lista.
 * Si el index es menor que cero no inserta el elemento.
 * Esta funci�n acepta DUPLICADOS.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size size_t Tama�o de la info a guardar.
 * \param index const int Indice en el que se quiere insertar la info.
 * \return int 1 Si la pudo insertar.
 */
int insert_simple_list(t_simple_list *l,const void *info, size_t size,const int index);


/** \brief
 * Inserta un rango de elementos desde un index recibido por par�metro de la funci�n.
 * Si el indice donde se quiere ingresar el elemento es mayor que la cantidad
 * de elementos de la lista, los elementos se insertan al final de la lista.
 * Si el index es menor que cero no inserta los elementos.
 * Esta funci�n acepta DUPLICADOS.
 * \param l t_simple_list* Puntero a la lista
 * \param arr const void* Puntero al arreglo con los elementos a insertar
 * \param size size_t Tama�o en bytes de cada elemento a insertar
 * \param ce const int Cantidad de elementos a agregar
 * \param index int Indice en el que se quiere insertar la info.
 * \return int 1 Si lo pudo insertar.
 */
int insert_range_simple_list(t_simple_list *l,const void *arr, size_t size,const int ce, int index);


/** \brief
 * Ordena la lista.
 * \param l t_simple_list* Puntero a la lista
 * \param size size_t Tama�o en bytes de cada elemento de la lista
 * \param comp t_comp Puntero a la funci�n de comparaci�n.
 * \return void
 */
void sort_simple_list(t_simple_list *l, size_t size, t_comp comp);



/** \brief
 * Elimina un elemento guardado en la lista.
 * Si el elemento est� duplicado, solo elimina la
 * primera ocurrencia.
 * \param l t_simple_list* Puntero a la lista
 * \param info void* Puntero al elemento que se quiere eliminar
 * \param size size_t Tama�o en bytes de los elementos de la lista.
 * \param comp t_comp Puntero a funci�n de comparaci�n.
 * \return int Si lo pudo eliminar.
 *
 */
int delete_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);


/** \brief
 * Elimina un elemento de la lista y todos sus duplicados.
 * \param l t_simple_list* Puntero a la lista
 * \param info void* Puntero al elemento que se quiere eliminar
 * \param size size_t Tama�o en bytes de los elementos de la lista.
 * \param comp t_comp Puntero a funci�n de comparaci�n.
 * \return int Si lo pudo eliminar.
 */
int delete_all_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);


/** \brief
 * Busca un elemento de la lista por su clave.
 * \param l t_simple_list* Puntero a la lista.
 * \param info void* info con la clave a buscar.
 * \param size size_t tama�o de la info guardada en la lista.
 * \param comp t_comp Puntero a la funci�n de comparaci�n.
 * \return int 1 Si la encontr�.
 */
int find_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);



/** \brief
 * Devuelve el indice que ocupa determinado elemento en lla lista.
 * busca por su clave desde la info que recibe por par�metro.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Info con la clave a buscar.
 * \param comp t_comp puntero a la funci�n de comparaci�n
 * \return int Index del elemento. -1 si el elemento no existe en la lista.
 */
int index_of_simple_list(t_simple_list *l, const void *info, t_comp comp);



/** \brief
 * Permite filtrar elementos a trav�s de una funci�n que recibe por par�metro.
 * La funci�n recibida arroja un Verdadero o una falso, y a partir de este valor
 * filtra los elementos de la lista retornando una nueva lista filtrada.
 * \param l t_simple_list* Puntero a la lista que se desea filtrar
 * \param size size_t Tama�o del tipo de dato guardado en la lista
 * \param filter t_filter Puntero a la funci�n que selecciona los elementos
 * \see *t_filter
 * \return t_simple_list Lista filtrada con los elementos requeridos.
 */
t_simple_list filter_simple_list(t_simple_list *l, size_t size, t_filter filter);



/** \brief
 * Vac�a y libera toda la informaci�n guardada en la lista.
 * \param l t_simple_list*
 * \return void
 */
void clear_simple_list(t_simple_list *l);


/** \brief
 *  Carga un arreglo con los elementos de la lista.
 * \param l t_simple_list* Puntero a la lista
 * \param arr void* Puntero al arreglo a cargar
 * \param size const size_t Tama�o de la info cargada en la lista
 * \return int 1 Si pudo cargar el arreglo.
 */
int to_array_simple_list(t_simple_list *l, void * arr, const size_t size);

#endif // SIMPLE_LIST_H_INCLUDED
