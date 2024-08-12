#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../libs/list_g.h"
#include "../libs/stack.h"
#include "../utils/utils.h"
#include "pba_stack.h"



void mostrar_module_stack()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCS",
        "Agregar Elementos",
        "Sacar elemento",
        "Ver Tope",
        "Salir"
    };
    t_list l;
    t_stack s;
    t_menu menu;
    init_menu(&menu, opciones,"TDA Pila");


    init_list(&l);
    init_stack(&s);

    char op;

    do{

        op = get_option(&menu);

        switch(op)
        {
            case 'A': pba_agregar_a_pila(&s,&l);
                break;
            case 'B': pba_sacar_elemento_a_pila(&s,&l);
                break;
        }

    }while(op != 's' && op != 'S');
}
