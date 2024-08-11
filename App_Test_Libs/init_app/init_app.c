#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../date_module/date_module.h"
#include "../tree_module/tree_module.h"
#include "../sort_module/sort_module.h"
void init_app()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "FOALPCS",
        "Fechas",
        "Ordenamiento",
        "Arbol Binario",
        "Lista Doble",
        "Pila Dinamica",
        "Cola Dinamica",
        "Salir"
    };

    t_menu menu;

    init_menu(&menu,opciones,"Test de Librerias");
    char op;

    do
    {
        op = get_option(&menu);

        switch(op)
        {
            case 'F': mostrar_module_date();
                break;
            case 'O': mostrar_module_sort();;
                break;
            case 'A': mostrar_module_tree();
                break;
        }
    }
    while(op != 'S' && op != 's');
}
