#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../libs/selection_sort.h"
#include "../libs/quicksort.h"
#include "pba_sort.h"



void mostrar_module_sort()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "AQVS",
        "Ordenamiento por Seleccion",
        "Ordenamiento Rapido",
        "Seleccion vs Ordenamiento Rapido",
        "Salir"
    };

    t_menu menu;
    init_menu(&menu, opciones,"TDA Ordenamiento");

    char op;

    do{

        op = get_option(&menu);

        switch(op)
        {
            case 'A': pba_ordenar_seleccion(selection_sort,"Ordenamiento Por Seleccion\n\n");
                break;
            case 'Q': pba_ordenar_seleccion(qs,"Ordenamiento Por QuickSort\n\n");
                break;
            case 'V': pba_qs_vs_sel ();
                break;
        }

    }while(op != 's' && op != 'S');

}
