#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"
#include "pba_tree.h"



void mostrar_module_tree()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDEFGHIJKLMNOS",
        "Agregar Elemento",
        "Cantidad de nodos del Arbol",
        "Altura del Arbol",
        "Recorrido In Orden",
        "Recorrido Pre Orden",
        "Recorrido Post Orden",
        "Nivel del Arbol",
        "Nivel de la Informacion",
        "Mostrar Nivel",
        "Eliminar Elemento",
        "Mostrar Grafico del Arbol",
        "Mostrar Hojas del Arbol",
        "Contar Hojas Del Arbol",
        "Podar Hojas",
        "Indexar Arvhivo Binario Ordenado",
        "Salir"
    };

    t_tree_set t;

    init_tree_set(&t);

    t_menu menu;
    init_menu(&menu, opciones,"TDA Fechas");

    char op;

    do{

        op = get_option(&menu);

        switch(op)
        {
            case 'A': pba_ingresar_elemento_arbol(&t);
                break;
        }

    }while(op != 's' && op != 'S');

}
