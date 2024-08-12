#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "pba_list.h"



void pba_mostrar_lista(t_list *l)
{
    printf("Listado\n\n");
    int info;

    printf("Lista=[ ");
    for(int i = 0; i < len_list(l); i ++)
    {
        get_info_list(l,&info,sizeof(int),i);
        printf("%d ",info);
    }
    printf("](%d Elementos)", len_list(l));
}

void pba_titulo_encabezado(const char *titulo, t_list *l)
{
    limpiar_mostrar_titulo(titulo);
    pba_mostrar_lista(l);
    saltos();
}

void pba_agregar_a_lista(t_list *l)
{
    char op;
    int val;
    do
    {
        pba_titulo_encabezado("Ingreso de elementos\n\n",l);

        val = ingresar_valor_entero("Ingrese el elemento: ");
        add_list(l,&val,sizeof(int));

        pba_titulo_encabezado("Ingreso de elementos\n\n",l);

        op = seleccionar_opcion("Desea seguir agregado(S/n): ");
    }
    while(op == 's' || op == 'S');
}


void pba_agregar_a_lista_en_orden(t_list *l)
{
    char op;
    int val;
    do
    {
        pba_titulo_encabezado("Ingreso de elementos en orden sin duplicados\n\n",l);

        val = ingresar_valor_entero("Ingrese el elemento: ");
        add_list_o(l,&val,sizeof(int), comp_in);

        limpiar();
        printf("Ingreso de elementos en orden sin duplicados\n\n");
        pba_mostrar_lista(l);

        printf("\n\n");

        op = seleccionar_opcion("Desea seguir agregado(S/n): ");
    }
    while(op == 's' || op == 'S');
}

void pba_agregar_a_lista_principio(t_list *l)
{
    char op;
    int val;
    do
    {
        pba_titulo_encabezado("Ingreso de elementos al principio\n\n",l);

        val = ingresar_valor_entero("Ingrese el elemento: ");
        add_first_list(l,&val,sizeof(int));

        pba_titulo_encabezado("Ingreso de elementos al principio\n\n",l);

        op = seleccionar_opcion("Desea seguir agregado(S/n): ");
    }
    while(op == 's' || op == 'S');
}


void pba_insertar_elemento(t_list *l)
{
    char op;
    int index, val;
    do
    {
        pba_titulo_encabezado("Insertar elemento en el Index\n\n",l);

        index = ingresar_valor_entero("Ingrese el index: ");
        val = ingresar_valor_entero("Ingrese el elemento: ");

        insert_list(l,&val,sizeof(int), index);
        pba_titulo_encabezado("Insertar elemento en el Index\n\n",l);

        op = seleccionar_opcion("Desea seguir insertando(S/n): ");
    }
    while(op == 's' || op == 'S');
}

void pba_insertar_elementos(t_list *l)
{
    char op;
    int index, ce;
    int *arr = NULL;

    do
    {
        pba_titulo_encabezado("Insertar elementos en el Index\n\n",l);

        index = ingresar_valor_entero("Ingrese el index: ");
        ce = ingresar_valor_entero("Ingrese la cantidad de elementos ");

        if(ce > 0 && index >= 0)
        {
            arr = (int *)malloc(sizeof(int)*ce);
            for(int i = 0; i < ce; i ++)
                *(arr + i) = ingresar_valor_entero("Ingrese el elemento: ");

            insert_range_list(l,arr,ce,sizeof(int),index);
            free(arr);
        }

        pba_titulo_encabezado("Insertar elementos en el Index\n\n",l);

        op = seleccionar_opcion("Desea seguir insertando(S/n): ");
    }
    while(op == 's' || op == 'S');
}


void pba_eliminar_elemento_lista(t_list *l)
{
    char op;
    int val;
    do
    {
        pba_titulo_encabezado("Eliminar un elemento\n\n",l);

        val = ingresar_valor_entero("Ingrese el elemento: ");

        delete_list(l,&val,sizeof(int), comp_in);
        pba_titulo_encabezado("Eliminar un elemento\n\n",l);

        op = seleccionar_opcion("Desea seguir eliminando(S/n): ");
    }
    while(op == 's' || op == 'S');
}


void pba_eliminar_elementos_lista(t_list *l)
{
    char op;
    int val;
    do
    {
        pba_titulo_encabezado("Eliminar un elemento y sus duplicados\n\n",l);

        val = ingresar_valor_entero("Ingrese el elemento: ");

        delete_all_list(l,&val,sizeof(int), comp_in);
        pba_titulo_encabezado("Eliminar un elemento y sus duplicados\n\n",l);

        op = seleccionar_opcion("Desea seguir eliminando(S/n): ");
    }
    while(op == 's' || op == 'S');
}


void pba_ordenar_lista(t_list *l)
{
    char o;
    pba_titulo_encabezado("Ordenar Lista\n\n",l);

    o = seleccionar_opcion("Desea Ordenar la lista(S/n): ");

    if(o == 's' || o == 'S')
        sort_list(l,sizeof(int), comp_in);

    pba_titulo_encabezado("Ordenar Lista\n\n",l);
    pausar();
}

void pba_ordenar_por_enlaces_lista(t_list *l)
{
    char o;
    pba_titulo_encabezado("Ordenar Lista por enlaces\n\n",l);

    o = seleccionar_opcion("Desea Ordenar la lista(S/n): ");

    if(o == 's' || o == 'S')
        sort_selection_list(l,sizeof(int), comp_in);

    pba_titulo_encabezado("Ordenar Lista\n\n",l);
    pausar();
}

