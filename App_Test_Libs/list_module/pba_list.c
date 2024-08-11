#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "pba_list.h"



void pba_mostrar_lista(t_list *l)
{
    printf("Listado\n\n");
    int info;

    printf("Lista=[ ");
    for(int i = 0; i < len_list(l); i ++){
        get_info_list(l,&info,sizeof(int),i);
        printf("%d ",info);
    }
    printf("]");
}

void pba_agregar_a_lista(t_list *l)
{
    char op;
    do{
        limpiar();
        printf("Ingreso de elementos\n\n");
        int val = ingresar_valor_entero("Ingrese el elemento: ");
        add_list(l,&val,sizeof(int));

        limpiar();
        printf("Ingreso de elementos\n\n");
        pba_mostrar_lista(l);

        printf("\n\n");

        op = seleccionar_opcion("Desea seguir agregado(S/n): ");
    }while(op == 's' || op == 'S');
}


void pba_agregar_a_lista_en_orden(t_list *l)
{
    char op;
    do{
        limpiar();
        printf("Ingreso de elementos en orden sin duplicados\n\n");
        int val = ingresar_valor_entero("Ingrese el elemento: ");
        add_list_o(l,&val,sizeof(int), comp_in);

        limpiar();
        printf("Ingreso de elementos en orden sin duplicados\n\n");
        pba_mostrar_lista(l);

        printf("\n\n");

        op = seleccionar_opcion("Desea seguir agregado(S/n): ");
    }while(op == 's' || op == 'S');
}

void pba_agregar_a_lista_principio(t_list *l)
{
    char op;
    do{
        limpiar();
        printf("Ingreso de elementos al principio\n\n");
        int val = ingresar_valor_entero("Ingrese el elemento: ");
        add_first_list(l,&val,sizeof(int));

        limpiar();
        printf("Ingreso de elementos al principio\n\n");
        pba_mostrar_lista(l);

        printf("\n\n");

        op = seleccionar_opcion("Desea seguir agregado(S/n): ");
    }while(op == 's' || op == 'S');
}
