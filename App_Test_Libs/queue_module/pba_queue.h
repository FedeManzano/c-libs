#ifndef PBA_QUEUE_H_INCLUDED
#define PBA_QUEUE_H_INCLUDED


#include "../libs/queue.h"
#include "../libs/list_g.h"


void pba_agregar_elemento_cola(t_queue *c, t_list *l);
void pba_sacar_elemento_a_cola(t_queue *c, t_list *l);
void pba_ver_tope_cola(t_queue *c, t_list *l);

void pba_vaciar_cola(t_queue *c, t_list *l);
#endif // PBA_QUEUE_H_INCLUDED
