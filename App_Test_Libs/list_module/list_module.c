#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../libs/list_g.h"
#include "pba_list.h"


//#include "pba_sort.h"



void mostrar_module_list()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDEFGHIJKS",
        "Agregar Elementos",
        "Agregar Elementos al Principio",
        "Agregar en Orden (Sin Duplicados)",
        "Agregar en Orden con Reemplazo (Sin Duplicados)",
        "Insertar Elemento en un Index",
        "Insertar un Rango de Elementos desde un Index",
        "Eliminar Elemento",
        "Eliminar Elemento y sus Duplicados",
        "Ordenar Seleccion",
        "Ordenar Seleccion intercambiando Direcciones",
        "Var Listado",
        "Salir"
    };
    t_list l;
    t_menu menu;
    init_menu(&menu, opciones,"TDA Ordenamiento");

    init_list(&l);
    char op;

    do{

        op = get_option(&menu);

        switch(op)
        {
            case 'A': pba_agregar_a_lista(&l);
                break;
            case 'B': pba_agregar_a_lista_principio(&l);
                break;
            case 'C': pba_agregar_a_lista_en_orden(&l);
                break;
        }

    }while(op != 's' && op != 'S');

}
