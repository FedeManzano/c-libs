#ifndef PBA_TREE_H_INCLUDED
#define PBA_TREE_H_INCLUDED
#include "../libs/tree_set.h"

typedef void (*t_recorrido)(t_tree_set *t, t_show show);


typedef struct {

    long dni;
    char apyn[50];
}t_persona;

typedef struct {

    long nro;
    long dni;
}t_ind;


void crear_archivo_prueba();

void pba_ingresar_elemento_arbol(t_tree_set *t);
void pba_cantidad_nodos_arbol(t_tree_set *t);
void pba_altura_arbol(t_tree_set *t);
void pba_rec(t_tree_set *t, t_recorrido recorrido, char *mje);
void pba_nivel_arbol(t_tree_set *t);
void pba_niveles_info_arbol(t_tree_set *t);
void pba_un_nivel_completo(t_tree_set *t);
void pba_eliminar_elemento(t_tree_set *t);
void pba_mostrar_arbol(t_tree_set *t);
void pba_mostrar_hojas(t_tree_set *t);
void pba_podar_hojas(t_tree_set *t);
#endif // PBA_TREE_H_INCLUDED
