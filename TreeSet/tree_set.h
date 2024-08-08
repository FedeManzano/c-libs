
/**
    TDA Arbol Binario

    void init_tree_set (t_tree_set *t);
    int is_empty_tree_set(const t_tree_set *t);
    int add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp);
    int count_tree_set(const t_tree_set *t);
    int height_tree_set(t_tree_set *t);
    int level_tree_set(t_tree_set *t);
    int count_leaf_tree_set(t_tree_set *t);
    int level_info_tree_set(t_tree_set *t,void *info, t_comp comp);
    int delete_tree_set(t_tree_set *t, const void *info,size_t size, t_comp comp);
    void delete_left_tree_set(t_tree_set *t);
    int find_tree_set(t_tree_set *t, void *info, size_t size, t_comp comp);
    void clear_tree_set(t_tree_set *t);
    void in_order_tree_set(t_tree_set *a, t_show show);
    void pre_order_tree_set(t_tree_set *t, t_show show);
    void post_order_tree_set(t_tree_set *t, t_show show);
    void show_graph_tree_set(t_tree_set *t, t_tree_set *aux,t_gra dib, t_comp comp);
    void show_level_tree_set(t_tree_set *t, int level, t_show show);
    void show_leaf_tree_set(t_tree_set *t, t_show show);

    ADV: La información ingresada al arbol es referenciada por un void *
    por lo tanto, para que el TDA funcione, hay que tener cuidado con la uniformidad del
    tipo de dato ingresado.
    Se pueden guardar datos de distintos tipos, pero no se van a poder acceder.

    @author Federico Manzano (https://github.com/FedeManzano)

*/

#ifndef TREE_SET_H_INCLUDED
#define TREE_SET_H_INCLUDED

#include "./libs/list_g.h"

#define _NULL_TREE          -10
#define _NULL_INFO          -9
#define _ERROR_SIZE         -8

#define _NO_FIND_ELE        0
#define _EMPTY_TREE         0
#define _FULL_TREE          0
#define _DUPLICATE_TREE     2
#define _OK                 1

/** \brief
 *
 * \param X
 * \return #define _IS_TREE_LEAF(X)(!(X)->l&&
 *
 */
#define _IS_TREE_LEAF(X)(!(X)->l && !(X)->r)



/** \brief
 */
typedef int (*t_comp)(const void *, const void *);


/** \brief
 */
typedef void (*t_gra)(const void *,const int lev);


typedef void (*t_read)(const void *info_arch,const void *info_arbol,const void *nro_reg);


/** \brief
 */
typedef void (*t_show)(const void *);

typedef struct s_tree_set {
    struct s_tree_set *l;
    struct s_tree_set *r;
    void * info;
}t_node_tree_set;

typedef t_node_tree_set * t_tree_set;


/** \brief
 *  Inicializa el arbol asingando NULL al puntero del arbol
 * \param Puntero al arbol
 * \param
 * \return
 *
 */
void init_tree_set (t_tree_set *t);


/** \brief
 *  Informa si el arbol está vacío o no.
 * \param t const t_tree_set* Puntero al arbol
 * \return int != si está vacío, 0 no está vacío
 *
 */
int is_empty_tree_set(const t_tree_set *t);


/** \brief
 *  Insertar elementos al árbol.
 * \param t t_tree_set* Puntero al arbol
 * \param info const void* Info a ingresar al arbol
 * \param size size_t Tamaño del dato
 * \param comp t_comp Función de comparación
 * \return int != 0 está vacío, 0  no lo está.
 *
 */
int add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp);


/** \brief
 * Cantidad de elementos dentro del árbol.
 * \param t const t_tree_set* Puntero al árbol
 * \return int Cantidad de elementos del árbol
 */
int count_tree_set(const t_tree_set *t);


/** \brief
 *
 * \param t t_tree_set*
 * \return int
 *
 */
int height_tree_set(t_tree_set *t);


/** \brief
 *
 * \param t t_tree_set*
 * \return int
 *
 */
int level_tree_set(t_tree_set *t);


/** \brief
 *
 * \param t t_tree_set*
 * \return int
 *
 */
int count_leaf_tree_set(t_tree_set *t);
int level_info_tree_set(t_tree_set *t,void *info, t_comp comp);
int delete_tree_set(t_tree_set *t, const void *info,size_t size, t_comp comp);
void delete_left_tree_set(t_tree_set *t);
int find_tree_set(t_tree_set *t, void *info, size_t size, t_comp comp);
void clear_tree_set(t_tree_set *t);
void in_order_tree_set(t_tree_set *a, t_show show);
void pre_order_tree_set(t_tree_set *t, t_show show);
void post_order_tree_set(t_tree_set *t, t_show show);
void show_graph_tree_set(t_tree_set *t, t_tree_set *aux,t_gra dib, t_comp comp);
void show_level_tree_set(t_tree_set *t, int level, t_show show);
void show_leaf_tree_set(t_tree_set *t, t_show show);



/** \brief
 * Esta función genera un indice de un archivo binario.
 * Obtiene uno por uno los registros de un archivo binario y guarda. En la información
 * del árbol {nroRegistro, info} el nro de registro y la información del registro.
 *
 * Ejemplo:
 * 10 - 32588877,"Nombre Apellido",FechaNac,FechaIng // Esto es un registro del archivo
 * en el arbol la info de este registro sería: nro:10 info:32588877 siendo diez el nro de registro en el archivo.
 *
 * \param t t_tree_set* Puntero al árbol
 * \param fi FILE** Archivo binario (ORDENADO POR CLAVE)
 * \param info_tree void* (Estructura que se guarda en el árbol nro,info)
 * \param size_tree const size_t (Tamaño del dato que se guarda en el árbol)
 * \param size_arch const size_t (Tamaño del registro que proviene del archivo)
 * \param comp t_comp Puntero a función de comparación
 * \param read t_read Puntero a la función que carga la estructura del árbol
          Ej:
          // El formato es importante tres * void en orden como se muestra
          void read_info(const void *info, const void *ia,const void *nro)
          {
                int * infoArch = (int *)info; // Info que proviene del archivo
                t_index * info_tree =(t_index *)ia; // Info que se carga en el arbol
                long * n = (long *)nro; //Nro de registro que ocupa en el archivo

                info_tree->info = *infoArch; // Carga la info del archivo
                info_tree->nro = *n; // Carga el nro de registro
          }

    \see t_read en la parte superior de este documento.
    \see test_archivo_arbol /la carpeta test de este proyecto
 * \return void
 *
 */
void file_binary_to_tree_set(t_tree_set *t, FILE **fi,void *info_tree, const size_t size_tree,const size_t size_arch, t_comp comp, t_read read);


/** Funciones para pruebas */
void to_array_in_order(t_tree_set *t, void *arr, size_t size);
void to_array_pre_order(t_tree_set *t, void *arr, size_t size);
void to_array_post_order(t_tree_set *t, void *arr, size_t size);


#endif // TREE_SET_H_INCLUDED
