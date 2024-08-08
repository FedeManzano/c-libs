
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

    ADV: La informaci�n ingresada al arbol es referenciada por un void *
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


#define _NULL_FILE          -3

#define _NO_FIND_ELE        0
#define _EMPTY_TREE         0
#define _FULL_TREE          0
#define _DUPLICATE_TREE     2
#define _OK                 1

/** \brief
 *  Establece si un nodo es hoja o no lo es
 * \param X t_tree_set * Puntero al �rbol
 * \return #define _IS_TREE_LEAF(X)(!(X)->l&& Verdadero si es hoja falso si no lo es.
 */
#define _IS_TREE_LEAF(X)(!(X)->l && !(X)->r)



/** \brief
* Permite comparar dos valores de la info cargada en el �rbol. A partir
* de esta funci�n el �rbol queda ordenado.
*/
typedef int (*t_comp)(const void *, const void *);


/** \brief
*   Permite pintar los nodos del arbo para generar el gr�fico.
 */
typedef void (*t_gra)(const void *,const int lev);


/** \brief
* Carga la info del arbol con la informaci�n del archivo
 */
typedef void (*t_read)(const void *info_arch,const void *info_arbol,const void *nro_reg);


/** \brief
* Sirve para mostrar un nodo del arbol cuando estamos recorriendolo.
 */
typedef void (*t_show)(const void *);


/**
Estructura de �rbol
*/
typedef struct s_tree_set {
    struct s_tree_set *l;
    struct s_tree_set *r;
    void * info;
}t_node_tree_set;

typedef t_node_tree_set * t_tree_set;


/** \brief
 *  Inicializa el arbol asingando NULL al puntero del arbol
 * \param Puntero al arbol
 */
void init_tree_set (t_tree_set *t);


/** \brief
 *  Informa si el arbol est� vac�o o no.
 * \param t const t_tree_set* Puntero al arbol
 * \return int != si est� vac�o, 0 no est� vac�o
 */
int is_empty_tree_set(const t_tree_set *t);


/** \brief
 *  Insertar elementos al �rbol.
 * \param t t_tree_set* Puntero al arbol
 * \param info const void* Info a ingresar al arbol
 * \param size size_t Tama�o del dato
 * \param comp t_comp Funci�n de comparaci�n
 * \return int != 0 est� vac�o, 0  no lo est�.
 *
 */
int add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp);


/** \brief
 * Cantidad de elementos dentro del �rbol.
 * \param t const t_tree_set* Puntero al �rbol
 * \return int Cantidad de elementos del �rbol
 */
int count_tree_set(const t_tree_set *t);


/** \brief
 * Calcula la altura del �rbol.
 * \param t t_tree_set* Puntero al �rbol
 * \return int Altura del �rbol
 *
 */
int height_tree_set(t_tree_set *t);


/** \brief
 * C�cula la cantidad de niveles del �rbol.
 * \param t t_tree_set* Puntero al �rbol
 * \return int Niveles del �rbol.
 *
 */
int level_tree_set(t_tree_set *t);


/** \brief
 * Calcula la cantidad de hojas que tiene el �rbol.
 * \param t t_tree_set*
 * \return int
 */
int count_leaf_tree_set(t_tree_set *t);


/** \brief
 *  Devuelve el nivel en el que se encuetra la info pasada por par�metro.
 * \param t t_tree_set* Puntero al �rbol.
 * \param info void* Info que se desea averiguar el nivel.
 * \param comp t_comp Puntero a la funci�n de comparaci�n
 * \return int Nivel de la info.
 *
 */
int level_info_tree_set(t_tree_set *t,void *info, t_comp comp);



/** \brief
 *  Borra un nodo del �rbol.
 * \param t t_tree_set* Puntero al �rbol
 * \param info const void* info que se desea eliminar
 * \param size size_t Tama�o en bytes del tipo de dato almacenado en el �rbol
 * \param comp t_comp Puntero a la funci�n de comparaci�n
 * \return int Si pudo eliminarlo OK.
 *
 */
int delete_tree_set(t_tree_set *t, const void *info,size_t size, t_comp comp);

/** \brief
 * Poda el arbol cortandole las hojas.
 * \param Puntero al �rbol
 */
void delete_left_tree_set(t_tree_set *t);



/** \brief
 * Busca por clave informaci�n dentro del �rbol.
 * \param t t_tree_set* Puntero al �rbol
 * \param info const void* info que se desea encontrar
 * \param size size_t Tama�o en bytes del tipo de dato almacenado en el �rbol
 * \param comp t_comp Puntero a la funci�n de comparaci�n
 * \return int Si pudo encontrarlo OK.
 */
int find_tree_set(t_tree_set *t, void *info, size_t size, t_comp comp);



/** \brief
 * Elimina todo el �rbol y libera la memoria asignada.
 * \param t t_tree_set*
 * \return void
 */
void clear_tree_set(t_tree_set *t);


/** \brief
 *  Recorre el arbol (In Order) y muestra sus nodos.
 * \param a t_tree_set* Puntero al �rbol
 * \param show t_show Puntero a funci�n para mostrar los nodos.
 * \return void
 */
void in_order_tree_set(t_tree_set *a, t_show show);


/** \brief
 *  Recorre el arbol (Pre Order) y muestra sus nodos.
 * \param a t_tree_set* Puntero al �rbol
 * \param show t_show Puntero a funci�n para mostrar los nodos.
 * \return void
 */
void pre_order_tree_set(t_tree_set *t, t_show show);


/** \brief
 *  Recorre el arbol (Post Order) y muestra sus nodos.
 * \param a t_tree_set* Puntero al �rbol
 * \param show t_show Puntero a funci�n para mostrar los nodos.
 * \return void
 */
void post_order_tree_set(t_tree_set *t, t_show show);



/** \brief
 * Permite genera un grafico esquem�tico del �rbol por pantalla.
 * Se apolla en la funci�n dib que muestra el nodo del �rbol en funci�n
 * al nivel de la info que se pretenda mostrar.
 *
 * ejemplo de funci�n dib:
 *
 *       void dibujar(const void  *info, const int niv) {
 *           int * in = (int *)info; // La info va a depender de que haya guardado en el �rbol
 *           int i;
 *           for(i = 0; i < niv; i ++)
 *               printf("      ");
 *           printf("[ %02d ]\n ", *in);
 *       }
 *
 * \param t t_tree_set* Puntero al �rbol
 * \param aux t_tree_set* Puntero a un �rbol auxiliar (El mismo �rbol)
 * \param dib t_gra (Funci�n para pintar el nodo en funci�n a su nivel dentro del �rbol)
 * \param comp t_comp Puntero a  la funci�n de comparaci�n.
 * \return void
 *
 */
void show_graph_tree_set(t_tree_set *t, t_tree_set *aux,t_gra dib, t_comp comp);


/** \brief
 * Muestra un nivel completo dentro del �rbol.
 * \param t t_tree_set* Puntero al �rbol
 * \param level int Nivel que sedea mostrar
 * \param show t_show Puntero a funci�n para mostrar el nodo
 * \return void
 *
 */
void show_level_tree_set(t_tree_set *t, int level, t_show show);


/** \brief
 *  Mostrar las hojas del �rbol
 * \param t t_tree_set*
 * \param show t_show
 * \return void
 *
 */
void show_leaf_tree_set(t_tree_set *t, t_show show);



/** \brief
 * Esta funci�n genera un indice de un archivo binario.
 * Obtiene uno por uno los registros de un archivo binario y guarda. En la informaci�n
 * del �rbol {nroRegistro, info} el nro de registro y la informaci�n del registro.
 *
 * Ejemplo:
 * 10 - 32588877,"Nombre Apellido",FechaNac,FechaIng // Esto es un registro del archivo
 * en el arbol la info de este registro ser�a: nro:10 info:32588877 siendo diez el nro de registro en el archivo.
 *
 * \param t t_tree_set* Puntero al �rbol
 * \param fi FILE** Archivo binario (ORDENADO POR CLAVE)
 * \param info_tree void* (Estructura que se guarda en el �rbol nro,info)
 * \param size_tree const size_t (Tama�o del dato que se guarda en el �rbol)
 * \param size_arch const size_t (Tama�o del registro que proviene del archivo)
 * \param comp t_comp Puntero a funci�n de comparaci�n
 * \param read t_read Puntero a la funci�n que carga la estructura del �rbol
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
void file_binary_to_tree_set(t_tree_set *t, FILE **fi, const size_t size_tree,const size_t size_arch, t_comp comp, t_read read);


/// Funciones para pruebas
/// Solo pueden ser utilizadas si disponemos de la lista doble
/// Agregada en este proyecto.
/// @see /libs/list_gg.c
///////////////////////////////////////////////////////////////////
void to_array_in_order(t_tree_set *t, void *arr, size_t size);
void to_array_pre_order(t_tree_set *t, void *arr, size_t size);
void to_array_post_order(t_tree_set *t, void *arr, size_t size);
///////////////////////////////////////////////////////////////////

#endif // TREE_SET_H_INCLUDED
