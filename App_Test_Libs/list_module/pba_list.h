#ifndef PBA_LIST_H_INCLUDED
#define PBA_LIST_H_INCLUDED
#include "../libs/list_g.h"
void pba_agregar_a_lista(t_list *l);
void pba_agregar_a_lista_en_orden(t_list *l);
void pba_agregar_a_lista_principio(t_list *l);
void pba_insertar_elemento(t_list *l);
void pba_insertar_elementos(t_list *l);
void pba_eliminar_elemento_lista(t_list *l);
void pba_eliminar_elementos_lista(t_list *l);
void pba_ordenar_lista(t_list *l);
void pba_ordenar_por_enlaces_lista(t_list *l);
#endif // PBA_LIST_H_INCLUDED
