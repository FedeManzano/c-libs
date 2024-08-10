#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../date_module/date_module.h"

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
        }
    }
    while(op != 'S' && op != 's');
}
