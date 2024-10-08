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
        "ABCDS",
        "Agregar Elementos",
        "Sacar Elemento",
        "Ver Tope",
        "Vaciar Pila",
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
            case 'C': pba_ver_tope_pila(&s,&l);
                break;
            case 'D': pba_vaciar_pila(&s,&l);
                break;
        }

        if(!is_empty_stack(&s) && (op == 'S' || op == 's'))
        {
            printf("\n\nHay elementos guardadas. Si sale pierde lo realizado.\n");
            char o = seleccionar_opcion("Desea salir y perder los cambios ? (S/N): ");
            if(o != 's' && o != 'S')
                op = '\0';
        } else if(op == 'S' || op == 's')
            clear_stack(&s);

    }while(op != 's' && op != 'S');
}
