#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../libs/list_g.h"
#include "pba_list.h"
#include "../utils/utils.h"



void mostrar_module_list()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDEFGHIS",
        "Agregar Elementos",
        "Agregar Elementos al Principio",
        "Agregar en Orden (Sin Duplicados)",
        "Insertar Elemento en un Index",
        "Insertar un Rango de Elementos desde un Index",
        "Eliminar Elemento",
        "Eliminar Elemento y sus Duplicados",
        "Ordenar Seleccion",
        "Ordenar Seleccion intercambiando Direcciones",
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
            case 'D': pba_insertar_elemento(&l);
                break;
            case 'E': pba_insertar_elementos(&l);
                break;
            case 'F': pba_eliminar_elemento_lista(&l);
                break;
            case 'G': pba_eliminar_elementos_lista(&l);
                break;
            case 'H': pba_ordenar_lista(&l);
                break;
            case 'I': pba_ordenar_por_enlaces_lista(&l);
                break;
        }
        if(!is_empty_list(&l) && (op == 'S' || op == 's'))
        {
            printf("\n\nHay elementos guardadas. Si sale pierde lo realizado.\n");
            char o = seleccionar_opcion("Desea salir y perder los cambios ? (S/N): ");
            if(o != 's' && o != 'S')
                op = '\0';
        } else if(op == 'S' || op == 's')
            clear_list(&l);

    }while(op != 's' && op != 'S');

}
