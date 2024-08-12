#ifndef PBA_STACK_H_INCLUDED
#define PBA_STACK_H_INCLUDED

#include "../libs/stack.h"
#include "../libs/list_g.h"



void pba_agregar_a_pila(t_stack *s, t_list *l);
void pba_sacar_elemento_a_pila(t_stack *s, t_list *l);
void pba_ver_tope_pila(t_stack *s, t_list *l);
void pba_vaciar_pila(t_stack *s, t_list *l);


#endif // PBA_STACK_H_INCLUDED
