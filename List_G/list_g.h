
/**
*   TDA Lista doblemente enlazada genérica.
*
*   Se puede utilizar para gestionar cualquier tipo de dato
*   utilizando void * para abstraer la lógica de la lista y que
*   pueda ser reutilizada.
*
*   void init_list(t_list * l);
*   int is_empty_list(const t_list *l);
*   int is_full_list(const t_list * l);
*   int len_list(t_list *l);
*   int add_first_list(t_list *l, const void *info, const int tam);
*   int add_list(t_list *l, const void *info, const int tam);
*   int add_list_o(t_list *l, const void *info,const int tam, t_comp comp);
*   int try_add_list_o(t_list *l,const void *info,const int tam, t_comp comp);
*   int get_key_list(t_list *l, void *info,const int tam, t_comp comp);
*   int get_key_last_list(t_list *l, void *info,const int tam, t_comp comp);
*   void * get_info_list(t_list *l,void *info,const int tam,const int index);
*   int delete_list(t_list *l, void *info,const int tam, t_comp comp);
*   int delete_all_list(t_list *l, void *info,const int tam, t_comp comp);
*   void sort_list(t_list *l,const int tam, t_comp comp);
*   void sort_link_list(t_list *l, t_comp comp);
*   int insert_list(t_list *l,const void * info,const int tam, const int index);
*   t_list filter_list(t_list *l, const size_t size, t_filter filter);
*   void clear_list(t_list *l);
*   int to_array_list(t_list *l, void *arr, int tam);
*   int update_list(t_list *l, const void *info, t_comp comp, t_update update);
*
*
*   Advertencia:
*
*   Esto es un TDA genérico, esto implica que la resposabilidad
*   de los tipos de datos ingresados a la lista es del usuario
*   que la utiliza.
*   Si ingresan a la misma lista varios tipos de datos y después
*   se producen errores, me desentiendo de la resposabilidad.
*
*
*   @author Federico Manzano (https://github.com/FedeManzano)
*/

#ifndef LIST_G_H_INCLUDED
#define LIST_G_H_INCLUDED


#define LIST_EMPTY      0
#define FULL_MEMORY     2
#define ELE_DUPLICATE   2
#define ELE_NO_FIND     0
#define LIST_NULL       -10
#define ERROR_INFO      -9
#define ERROR_IMP       -1
#define INDEX_BOUNDS    -8
#define OK              1




/**
    Prototipo para crear funciones de este tipo
    y poder comparar elementos.
    @return resultado de la comparación.
*/
typedef int (*t_comp)(const void *, const void *);
typedef int (*t_filter)(const void *);
typedef void (*t_update)(void *info_list, const void *info_update);


typedef struct s_node_list
{
    struct s_node_list * next;
    struct s_node_list  * back;
    void * info;
} t_node_list;

typedef t_node_list* t_list;




/** \brief
 *  Inicializa la lista asignando al puntero de lista *l = NULL
 *
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \return void
 *
 */
void init_list(t_list * l);



/** \brief
 *  Permite conocer el estado de la lista si tiene o no elementos.
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \return int != 0 si esta vacía y 0 si no lo está.
 *
 */
int is_empty_list(const t_list *l);


/** \brief
 *  Permite conocer si existe memoria para agregar más información o no.
    @example
        if(!is_full_list(&l))
            add_list(...)
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \return int != 0 si está llena 0 si no lo está.
 *
 */
int is_full_list(const t_list * l);



/** \brief
 * Devuelve la cantidad de elementos almacenados en la lista.
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \return int cantidad de elementos.
 *
 */
int len_list(t_list *l);


/** \brief
 *  Guarda un elemento al comienzo de la lista. (Permite duplicados)
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \param info const void* info que desea guardar
 * \param tam const int tamaño del tipo de dato de la info a guardar
 * \return int Si pudo guardar el dato o no lo pudo guardar.
            OK -> guardó el dato.
            LIST_NULL -> -10.
            ERROR_INFO -> -9 info nula.
            FULL_MEMORY -> 2 Está llena la memoria.
 *
 */
int add_first_list(t_list *l, const void *info, const size_t tam);

/** \brief
 * Guarda el elemento al final de la lista. (Permite duplicados)
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \param info const void* info que desea guardar
 * \param tam const int tamaño del tipo de dato de la info a guardar
 * \return int Si pudo guardar el dato o no lo pudo guardar.
            OK -> guardó el dato.
            LIST_NULL -> -10.
            ERROR_INFO -> -9 info nula.
            FULL_MEMORY -> 2 Está llena la memoria.
 *
 */
int add_list(t_list *l, const void *info, const size_t tam);

/** \brief
 * Guarda el elemento en orden en la lista. (No permite duplicados)
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \param info const void* info que desea guardar
 * \param tam const int tamaño del tipo de dato de la info a guardar
 * \return int Si pudo guardar el dato o no lo pudo guardar.
            OK -> guardó el dato.
            LIST_NULL -> -10.
            ERROR_INFO -> -9 info nula.
            FULL_MEMORY -> 2 Está llena la memoria.
 *
 */
int add_list_o(t_list *l, const void *info,const size_t tam, t_comp comp);

/** \brief
 * Guarda el elemento en orden en la lista. (No permite duplicados),
 * Si entra un elemento repetido, este, reemplza al anterior.
 * \param l t_list* t_node ** de la struct utilizada para la lista.
 * \param info const void* info que desea guardar
 * \param tam const int tamaño del tipo de dato de la info a guardar
 * \return int Si pudo guardar el dato o no lo pudo guardar.
            OK -> guardó el dato.
            LIST_NULL -> -10.
            ERROR_INFO -> -9 info nula.
            FULL_MEMORY -> 2 Está llena la memoria.
 *
 */
int try_add_list_o(t_list *l,const void *info,const size_t tam, t_comp comp);



/** \brief
 * Busca por clave a un elemento dentro de la lista.
 * \param l t_list*
 * \param info void*
 * \param tam const int Tamaño de dato de los elementos guardados en la lista
 * \param comp t_comp Puntero a función de comparación.
 * \return int 1 si fue exitosa la busqueda 0 si no lo fue.
 *
 */
int get_key_list(t_list *l, void *info,const size_t tam, t_comp comp);

/** \brief
 * Busca por clave a un elemento dentro de la lista empezando la busqueda desde el
 * final de la misma.
 * \param l t_list*
 * \param info void*
 * \param tam const int Tamaño de dato de los elementos guardados en la lista
 * \param comp t_comp Puntero a función de comparación.
 * \return int 1 si fue exitosa la busqueda 0 si no lo fue.
 *
 */
int get_key_last_list(t_list *l, void *info,const size_t tam, t_comp comp);


/** \brief
 * Devuelve un elemento de la lista por su posición en la misma.
 * \param l t_list*
 * \param info void*
 * \param tam const int Tamaño de dato de los elementos guardados en la lista
 * \param const int index indice del elemento buscado
 * \return void * con la info del elemento de index pasado por parámetro.
 *
 */
void * get_info_list(t_list *l,void *info,const size_t tam,const int index);


/** \brief
 *  Elimina un elemento de la lista pasado por parámetro.
    Si el elemento aparece varias veces en la lista, solo elimina
    la primera ocurrencia.
 * \param l t_list* Puntero a la lista
 * \param info void* Elemento a eliminar
 * \param tam const int Tamaño de la información guardada en la lista
 * \param comp t_comp Puntero a la función de comparación
 * \return int Si pudo eliminar OK sino ELE_NO_FIND
 */
int delete_list(t_list *l, void *info,const size_t tam, t_comp comp);

/** \brief
 *  Elimina un elemento o más elementos de la lista dependiendo
    si el elemento pasado por parámetro está repetido o no.
    Elimina todas las ocurrencias del elemento.
 * \param l t_list* Puntero a la lista
 * \param info void* Elemento a eliminar
 * \param tam const int Tamaño de la información guardada en la lista
 * \param comp t_comp Puntero a la función de comparación
 * \return int Si pudo eliminar OK sino ELE_NO_FIND
 */
int delete_all_list(t_list *l, void *info,const size_t tam, t_comp comp);


/** \brief
 *  Ordena la lista en forma creciente.
 * \param l t_list* Puntero a la lista
 * \param tam const int tamaño de los datos guardados en la lista.
 * \param comp t_comp puntero a función de comparación
 * \return void
 */
void sort_list(t_list *l,const size_t tam, t_comp comp);


/** \brief
 *  Ordena la lista en forma creciente.
 *  Recomendada para estructuras complejas en caso
 *  contrario es ineficiente.
 * \param l t_list* Puntero a la lista
 * \param tam const int tamaño de los datos guardados en la lista.
 * \param comp t_comp puntero a función de comparación
 * \return void
 */
void sort_selection_list(t_list *l,const size_t tam, t_comp comp);



/** \brief
 *  Permite insertar un elemento en la lista en un index pasado
    por parámetro.
 * \param l t_list* Puntero a la lista.
 * \param info const void* Información a insertar.
 * \param tam const int tamaño del tipo de dato de la lista.
 * \param index const int indice donde se quiere insertar el elemento
          tiene que ser >=0, si el valor exede la cantidad de elementos
          que tiene la lista, la función, insertará el elemento al final
          de la lista.
 * \return int Si lo pudo insertar o no.
 */
int insert_list(t_list *l,const void * info,const size_t tam, const int index);

/** \brief
 *  Inserta un rango de elementos en la lista.
 * \param l t_list* Puntero a la lista.
 * \param arr const void* Puntero a los elementos que se desean agregar.
 * \param tam const int tamaño del tipo de dato de la lista.
 * \param index const int indice donde se quiere insertar el elemento
          tiene que ser >=0, si el valor exede la cantidad de elementos
          que tiene la lista, la función, insertará el elemento al final
          de la lista.
 * \return int Si lo pudo insertar o no.
 */
int insert_range_list(t_list *l,const void * arr,const int ce,const size_t tam, int index);

/** \brief
 * Vaciar la lista eliminando todos los nodos contenidos.
 * \param l t_list* Puntero a la lista
 * \return void
 *
 */
void clear_list(t_list *l);


/** \brief
 * Devuelve un arreglo con los elementos de la lista.
 * \param l t_list* Puntero a la lista
 * \param arr void* Erreglo donde cargarán los datos de la lista
 * \param tam int Tamaño de la info dentro de la lista.
 * \return int Si pudo cargar el arreglo o no pudo hacerlo.
 */
int to_array_list(t_list *l, void *arr,const size_t tam);


/** \brief
 * Permite aplicarle un filtro a la lista.
 * Generando un conjunto de elementos nuevo en función a una condición
 * que viene desde un putero a una función del tipo t_filter.
 * @see *t_filter
 * \param l t_list* Puntero a la lista
 * \param size const size_t
 * \param filter t_filter Puntero a la función filtro
 * \return t_list Lista filtrada después de aplicarle el filtro.
 */
t_list filter_list(t_list *l, const size_t size, t_filter filter);

/** \brief
 *  Devuelve el index que tiene el elemento pasado por parámetro
    en la lista.
 * \param l t_list* Puntero a la lista
 * \param info const void* info que se quiere conocer su index
 * \param tam const int Tamaño del dato que se guarda en la lista
 * \param comp t_comp Puntero a función de comparación
 * \return int index si el elemento existe o -1 si no existe.
 *
 */
int index_of_list(t_list *l, const void *info,const int tam, t_comp comp);


/** \brief
 * Permite actualizar un nodo de la lista con la información
 * que ingresa por parámetro.
 * \param l t_list* Puntero a la lista
 * \param info const void* Puntero con la información a actualizar.
 * \param comp t_comp Puntero al la función de comparación.
 * \param update t_update Puntero a la función de comparación.
 * \return int Si pudo actualizar 1 / caso contrario 0
 */
int update_list(t_list *l, const void *info, t_comp comp, t_update update);

#endif // LIST_G_H_INCLUDED
