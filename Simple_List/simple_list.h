
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
    t_simple_list sub_simple_list(t_simple_list *l, const size_t size, const int start, const int end);
    int equals_simple_list(t_simple_list *l1, t_simple_list *l2, t_comp comp);
    t_simple_list intersection_simple_list(t_simple_list *l1, t_simple_list *l2,const size_t size, t_comp comp);
    t_simple_list subtract_simple_list(t_simple_list *l1, t_simple_list *l2, const size_t size, t_comp comp);
    t_simple_list union_simple_list(t_simple_list *l1, t_simple_list *l2, const size_t size, t_comp comp);
    int file_to_list(t_simple_list *l, const char *path, const size_t size);
    int list_to_file(t_simple_list *l, const char * path, const size_t size);

    ADV:

    Los tipos de datos agregados a este TDA son genéricos,
    por lo tanto, en cada lista creada es responsabilidad del
    programador almacer el mismo tipo de dato.

    @author Federico Manzano (https://github.com/FedeManzano)
*/

#ifndef SIMPLE_LIST_H_INCLUDED
#define SIMPLE_LIST_H_INCLUDED


#define _SIMPLE_LIST_NULL   -10
#define _SIMPLE_LIST_INFO   -9
#define _SIMPLE_LIST_SIZE   -8
#define _SIMPLE_LIST_INDEX  -7

#define _SIMPLE_LIST_EMPTY  0
#define _SIMPLE_LIST_FULL   0
#define _SIMPLE_LIST_DUP    2
#define _SIMPLE_LIST_NO_INSERT  -1
#define _SIMPLE_LIST_NO_DELETE  -1
#define _SIMPLE_LIST_NO_FIND    -1
#define _SIMPLE_LIST_OK          1
#define _SIMPLE_LIST_EQUALS      1
#define _SIMPLE_LIST_NO_EQUALS   0
#define _SIMPLE_NO_INTERSECTION  0


/** \brief
    Puntero a función de comparación.
 */
typedef int (*t_comp)(const void *,const void *);

typedef int (*t_filter)(const void *);

/** \brief
    Puntero a función que permite actualizar uno de los
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
 *  Permite conocer si la lista está vacía o
    tiene elementos.
 * \param l t_simple_list* Puntero a la lista
 * \return int Si está vacía retorna != 0.
 */
int is_empty_simple_list(t_simple_list *l);


/** \brief
 * Permite conocer si hay espacio en la memoria para almacenar
 * un elemento nuevo.
 * \param l t_simple_list* Puntero a la lista
 * \return int Distinto de 0 si está llena. Caso contrario hay espacio.
 *
 */
int is_full_simple_list(t_simple_list *l);


/** \brief
 *  Agrega un elemento al final de la lista.
 * \param  l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la información a guardar.
 * \param size const size_t Tamaño de la información a guardar.
 * \return int 1 Si logró agregar la info. != 1 si hubo algún problema.
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
 * Permite acceder el elemento de la lista de index pasado por parámetro.
 * \param l t_simple_list* Puntero a la lista
 * \param info void* Puntero donde se cargará la info solicitada.
 * \param size size_t Tamaño de la información que se solicita.
 * \param index const int indice del cual se quiere acceder a la info.
 * \return int 1 Si encontro la información. != 1 si no la encontró.
 *
 */
int get_simple_list(t_simple_list *l, void *info, size_t size, const int index);


/** \brief
 * Agrega un elemento a la lista de manera ordenada.
 * Utilizando la función de comparación recibida por parámetro.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Info que se desea guardar.
 * \param size const size_t Tamaño de la información que se desea guardar.
 * \param comp t_comp Puntero a función de comparación
 * \return int 1 Si la pudo guardar. != 1 si hubo problemas.
 *
 */
int add_simple_list_in_order(t_simple_list *l, const void *info, const size_t size, t_comp comp);


/** \brief
 * Añade un elemento a la lista al comienzo de la misma.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info que se desea guardar.
 * \param size const size_t Tamaño de la info a guardar.
 * \return int 1 si la pudo guardar.
 */
int add_first_simple_list(t_simple_list *l, const void *info, const size_t size);



/** \brief
 * Guarda un elemento en la lista de manera ordenada.
 * Esta función no permite duplicados. Si el elemento a ingresar
 * ya se encontraba en la lista, este de descarta.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size const size_t Tamaño de la info a guardar.
 * \param comp t_comp Puntero a la función de comparación.
 * \return int 1 si pudo agregar la info.
 */
int add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);


/** \brief
 * Guarda un elemento en la lista de manera ordenada.
 * Esta función no permite duplicados. Si el elemento a ingresar
 * ya se encontraba en la lista, esta función lo reemplaza con el nuevo elemento duplicado.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size const size_t Tamaño de la info a guardar.
 * \param comp t_comp Puntero a la función de comparación.
 * \return int 1 si pudo agregar la info.
 */
int try_add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);



/** \brief
 * Esta función permite agregar un elemento de forma ordenada.
 * Si el elemento ya se encuentra en la lista, esta función permite la actualización de
 * la información que recide en la lista con la nueva información que viene por parámetro.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size const size_t Tamaño de la info a guardar.
 * \param comp t_comp Puntero a la función de comparación.
 * \param update t_update Puntero a función que permite la actualización de la info de la lista.
 * \return int 1 si pudo almacenar el nodo. 2 si lo actualizó. un valor diferente es por error.
 */
int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update);



/** \brief
 * Inserta un elemento en un index recibido por parámetro de la función.
 * Si el indice donde se quiere ingresar el elemento es mayor que la cantidad
 * de elementos de la lista, el mismo se inserta al final de la lista.
 * Si el index es menor que cero no inserta el elemento.
 * Esta función acepta DUPLICADOS.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Puntero a la info a guardar.
 * \param size size_t Tamaño de la info a guardar.
 * \param index const int Indice en el que se quiere insertar la info.
 * \return int 1 Si la pudo insertar.
 */
int insert_simple_list(t_simple_list *l,const void *info, size_t size,const int index);


/** \brief
 * Inserta un rango de elementos desde un index recibido por parámetro de la función.
 * Si el indice donde se quiere ingresar el elemento es mayor que la cantidad
 * de elementos de la lista, los elementos se insertan al final de la lista.
 * Si el index es menor que cero no inserta los elementos.
 * Esta función acepta DUPLICADOS.
 * \param l t_simple_list* Puntero a la lista
 * \param arr const void* Puntero al arreglo con los elementos a insertar
 * \param size size_t Tamaño en bytes de cada elemento a insertar
 * \param ce const int Cantidad de elementos a agregar
 * \param index int Indice en el que se quiere insertar la info.
 * \return int 1 Si lo pudo insertar.
 */
int insert_range_simple_list(t_simple_list *l,const void *arr, size_t size,const int ce, int index);


/** \brief
 * Ordena la lista.
 * \param l t_simple_list* Puntero a la lista
 * \param size size_t Tamaño en bytes de cada elemento de la lista
 * \param comp t_comp Puntero a la función de comparación.
 * \return void
 */
void sort_simple_list(t_simple_list *l, size_t size, t_comp comp);



/** \brief
 * Elimina un elemento guardado en la lista.
 * Si el elemento está duplicado, solo elimina la
 * primera ocurrencia.
 * \param l t_simple_list* Puntero a la lista
 * \param info void* Puntero al elemento que se quiere eliminar
 * \param size size_t Tamaño en bytes de los elementos de la lista.
 * \param comp t_comp Puntero a función de comparación.
 * \return int Si lo pudo eliminar.
 *
 */
int delete_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);


/** \brief
 * Elimina un elemento de la lista y todos sus duplicados.
 * \param l t_simple_list* Puntero a la lista
 * \param info void* Puntero al elemento que se quiere eliminar
 * \param size size_t Tamaño en bytes de los elementos de la lista.
 * \param comp t_comp Puntero a función de comparación.
 * \return int Si lo pudo eliminar.
 */
int delete_all_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);


/** \brief
 * Busca un elemento de la lista por su clave.
 * \param l t_simple_list* Puntero a la lista.
 * \param info void* info con la clave a buscar.
 * \param size size_t tamaño de la info guardada en la lista.
 * \param comp t_comp Puntero a la función de comparación.
 * \return int 1 Si la encontró.
 */
int find_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);



/** \brief
 * Devuelve el indice que ocupa determinado elemento en lla lista.
 * busca por su clave desde la info que recibe por parámetro.
 * \param l t_simple_list* Puntero a la lista
 * \param info const void* Info con la clave a buscar.
 * \param comp t_comp puntero a la función de comparación
 * \return int Index del elemento. -1 si el elemento no existe en la lista.
 */
int index_of_simple_list(t_simple_list *l, const void *info, t_comp comp);



/** \brief
 * Permite filtrar elementos a través de una función que recibe por parámetro.
 * La función recibida arroja un Verdadero o una falso, y a partir de este valor
 * filtra los elementos de la lista retornando una nueva lista filtrada.
 * \param l t_simple_list* Puntero a la lista que se desea filtrar
 * \param size size_t Tamaño del tipo de dato guardado en la lista
 * \param filter t_filter Puntero a la función que selecciona los elementos
 * \see *t_filter
 * \return t_simple_list Lista filtrada con los elementos requeridos.
 */
t_simple_list filter_simple_list(t_simple_list *l, size_t size, t_filter filter);



/** \brief
 * Vacía y libera toda la información guardada en la lista.
 * \param l t_simple_list*
 * \return void
 */
void clear_simple_list(t_simple_list *l);


/** \brief
 *  Carga un arreglo con los elementos de la lista.
 * \param l t_simple_list* Puntero a la lista
 * \param arr void* Puntero al arreglo a cargar
 * \param size const size_t Tamaño de la info cargada en la lista
 * \return int 1 Si pudo cargar el arreglo.
 */
int to_array_simple_list(t_simple_list *l, void * arr, const size_t size);


/** \brief
 * Devuelve un sublista de la lista original limitandola con los
 * parámetros start y end.
 * Si dichos parámetros son validos devuelve la sublista, caso
 * contrario devuelve NULL.
 * Cuando la lista retornada no se utilice mas hay que liberarla.
 * EJ: free(lista).
 * \param l t_simple_list* Puntero a la lista.
 * \param size const size_t Tamaño del tipo de dato guardado en la lista.
 * \param start const int Inicio de la sublista
 * \param end const int elemento final de la sublista.
 * \return t_simple_list Sub lista retornada.
 */
t_simple_list sub_simple_list(t_simple_list *l, const size_t size, const int start, const int end);



/** \brief
 * Compara si dos listas simples son iguales.
 * \param l1 t_simple_list* Puntero a la lista 1
 * \param l2 t_simple_list* Puntero a la lista 2
 * \param comp t_comp Puntero a la función de comparación
 * \return int 1 si son iguales 0 si no lo son.
 */
int equals_simple_list(t_simple_list *l1, t_simple_list *l2, t_comp comp);


/** \brief
 * Devulve el conjunto intersección de elementos de la lista 1 y la lista 2.
 * Devulve una lista vacía si no hay elementos en común.
 * La lista resultado se crea dinámicamente, por esta razón hay que liberarla.
 * No conserva los DUPLICADOS.
 * free(intersección); // Cuando se termine de utilizar.
 * Ejemplo:
 *
 * t_simple_list intersection = intersection_simple_list(&l1, &l2,sizeof(int),comp_int);
 * while(!is_empty_simple_list(&intersection))
 * {
 *     /// Procesar lista intersección
 * }
 * // Ya procesada
 * free(interseccion); // Libera el recurso
 * \param l1 t_simple_list* Puntero a la lista 1
 * \param l2 t_simple_list* Puntero a la lista 2
 * \param size const size_t Tamaño del topo de dato
 * \param comp t_comp Puntero a la función de comparación
 * \return t_simple_list Lista intersección.
 */
t_simple_list intersection_simple_list(t_simple_list *l1, t_simple_list *l2,const size_t size, t_comp comp);


/** \brief
 * Resta la lista l2 a la l1.
 * No conserva los duplicados.
 * \param l1 t_simple_list* Puntero a la lista 1
 * \param l2 t_simple_list* Puntero a la lista 2
 * \param size const size_t Tamaño de la info almacenada
 * \param comp t_comp Puntero a función de comparación
 * \return t_simple_list Lista restada l1 - l2
 */
t_simple_list subtract_simple_list(t_simple_list *l1, t_simple_list *l2, const size_t size, t_comp comp);


/** \brief
 * Devuelve una lista con todos los elementos de la lista 1 y la lista 2.
 * No carga elementos DUPLICADOS.
 * \param l1 t_simple_list* Puntero a la lista 1
 * \param l2 t_simple_list* Puntero a la lista 2
 * \param size const size_t Tamaño de la info almacenada
 * \param comp t_comp Puntero a función de comparación
 * \return t_simple_list Lista restada l1 - l2
 */
t_simple_list union_simple_list(t_simple_list *l1, t_simple_list *l2, const size_t size, t_comp comp);


/** \brief
 * Pasa el contenido de un archivo .dat a una lista.
 * \param l t_simple_list* Puntero a la lista
 * \param path const char* Path del archivo.
 * \param size const size_t Tamaño del tipo de dato.
 * \return int 1 Si pudo pasar el archivo, 0 sino pudo.
 */
int file_to_simple_list(t_simple_list *l, const char *path, const size_t size);


/** \brief
 * Pasa una lista a un archivo.
 * El archivo se sobreescribe por lo tanto tiene que ser un archivo vacio.
 * Si el archivo no existe lo crea.
 * \param l t_simple_list* Puntero a la lista.
 * \param path const char* Path del archivo.
 * \param size const size_t Tamaño del tipo de dato.
 * \return int 1 Si la pudo pasar, 0 sino pudo.
 */
int simple_list_to_file(t_simple_list *l, const char * path, const size_t size);


#endif // SIMPLE_LIST_H_INCLUDED
