#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "pba_stack.h"


void pba_mostrar_pila(t_list * l)
{
    int info;
    printf("Pila=[ ");
    for(int i = 0; i < len_list(l); i ++)
    {
        get_info_list(l,&info,sizeof(int), i);
        printf("%d ",info);
    }
    printf(" ](%d Elementos)",len_list(l));
}

void pba_limpiar_y_mostrar_encabezado(const char *mje,t_list *l)
{
    limpiar_mostrar_titulo(mje);
    saltos();
    pba_mostrar_pila(l);
    saltos();
}


void pba_agregar_a_pila(t_stack *s, t_list *l)
{
    char op;
    int val;

    do {
        pba_limpiar_y_mostrar_encabezado("Agregar Elemento a la Pila", l);
        val = ingresar_valor_entero("Ingrese el elemento a agregar(Entero): ");
        push_stack(s,&val,sizeof(int));
        add_first_list(l,&val,sizeof(int));

         pba_limpiar_y_mostrar_encabezado("Agregar Elemento a la Pila", l);

        op = seleccionar_opcion("Desea seguir agregando elementos(S/N): ");
    }while(op == 'S' || op == 's');

}


void pba_sacar_elemento_a_pila(t_stack *s, t_list *l)
{
    char op, o;
    int val;

    do {
        pba_limpiar_y_mostrar_encabezado("Sacar elemento de la pila", l);

        o = seleccionar_opcion("Desea extraer un elemento? (S/N): ");
        if(o == 'S' || o == 's')
        {
            pop_stack(s,&val,sizeof(int));
            delete_list(l,&val,sizeof(int),comp_in);
            saltos();
            printf("El elemento extaido es: %d", val);
            saltos();
            pausar();
        }

        pba_limpiar_y_mostrar_encabezado("Sacar elemento de la pila", l);

        op = seleccionar_opcion("Desea seguir sacando elementos(S/N): ");
    }while(op == 'S' || op == 's');
}


void pba_ver_tope_pila(t_stack *s, t_list *l)
{
    int val;
    pba_limpiar_y_mostrar_encabezado("Ver tope de pila", l);

    if(!is_empty_stack(s)){
        top_stack(s,&val,sizeof(int));
        printf("El tope de pila es: %d",val);
    } else printf("La pila esta vacia");

    saltos();
    pausar();
}


void pba_vaciar_pila(t_stack *s, t_list *l)
{
    char op;
    pba_limpiar_y_mostrar_encabezado("Vaciar Pila", l);

    op = seleccionar_opcion("Desea vaciar la pila(S/N): ");
    if(op == 's' || op == 'S'){
        clear_stack(s);
        clear_list(l);
    }

    pba_limpiar_y_mostrar_encabezado("Vaciar Pila", l);
    pausar();
}
