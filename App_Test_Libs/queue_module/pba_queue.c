#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "pba_queue.h"

void pba_mostrar_cola(t_list * l)
{
    int info;
    printf("Cola=[ ");
    for(int i = 0; i < len_list(l); i ++)
    {
        get_info_list(l,&info,sizeof(int), i);
        printf("%d ",info);
    }
    printf(" ](%d Elementos)",len_list(l));
}

void pba_limpiar_y_mostrar_encabezado_cola(const char *mje,t_list *l)
{
    limpiar_mostrar_titulo(mje);
    saltos();
    pba_mostrar_cola(l);
    saltos();
}

void pba_agregar_elemento_cola(t_queue *c, t_list *l) {

    char op;
    int val;

    do {
        pba_limpiar_y_mostrar_encabezado_cola("Agregar Elemento a la Cola", l);
        val = ingresar_valor_entero("Ingrese el elemento a agregar(Entero): ");

        push_queue(c,&val,sizeof(int));
        add_list(l,&val,sizeof(int));

        pba_limpiar_y_mostrar_encabezado_cola("Agregar Elemento a la Cola", l);

        op = seleccionar_opcion("Desea seguir agregando elementos(S/N): ");
    }while(op == 'S' || op == 's');
}

void pba_sacar_elemento_a_cola(t_queue *c, t_list *l)
{
    char op, o;
    int val;

    do {
        pba_limpiar_y_mostrar_encabezado_cola("Sacar elemento de la cola", l);

        o = seleccionar_opcion("Desea extraer un elemento? (S/N): ");
        if(o == 'S' || o == 's')
        {
            pop_queue(c,&val,sizeof(int));
            delete_list(l,&val,sizeof(int),comp_in);
            saltos();
            printf("El elemento extaido es: %d", val);
            saltos();
            pausar();
        }

        pba_limpiar_y_mostrar_encabezado_cola("Sacar elemento de la cola", l);

        op = seleccionar_opcion("Desea seguir sacando elementos(S/N): ");
    }while(op == 'S' || op == 's');
}

void pba_ver_tope_cola(t_queue *c, t_list *l)
{
    int val;
    pba_limpiar_y_mostrar_encabezado_cola("Ver tope de pila", l);

    if(!is_empty_queue(c)){
        top_queue(c,&val,sizeof(int));
        printf("El tope de cola es: %d",val);
    } else printf("La cola esta vacia");

    saltos();
    pausar();
}

void pba_vaciar_cola(t_queue *c, t_list *l)
{
    char op;
    pba_limpiar_y_mostrar_encabezado_cola("Vaciar Pila", l);

    op = seleccionar_opcion("Desea vaciar la cola(S/N): ");
    if(op == 's' || op == 'S'){
        clear_queue(c);
        clear_list(l);
    }

    pba_limpiar_y_mostrar_encabezado_cola("Vaciar cola", l);
    pausar();
}
