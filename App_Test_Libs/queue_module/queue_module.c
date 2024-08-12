#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../libs/list_g.h"
#include "../libs/queue.h"
#include "../utils/utils.h"
#include "pba_queue.h"


void mostrar_module_queue()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDS",
        "Agregar Elemento",
        "Sacar Elemento",
        "Ver Primer Elemento",
        "Vaciar Cola",
        "Salir"
    };

    t_queue q;
    t_menu menu;
    t_list l;

    char op;

    init_menu(&menu, opciones,"TDA Cola");
    init_queue(&q);
    init_list(&l);



    do{

        op = get_option(&menu);

        switch(op)
        {
            case 'A': pba_agregar_elemento_cola(&q,&l);
                break;
            case 'B': pba_sacar_elemento_a_cola(&q,&l);
                break;
            case 'C': pba_ver_tope_cola(&q,&l);
                break;
            case 'D': pba_vaciar_cola(&q,&l);
                break;
        }

        if(!is_empty_queue(&q) && (op == 'S' || op == 's'))
        {
            printf("\n\nHay elementos guardadas. Si sale pierde lo realizado.\n");
            char o = seleccionar_opcion("Desea salir y perder los cambios ? (S/N): ");
            if(o != 's' && o != 'S')
                op = '\0';
        } else if(op == 'S' || op == 's')
            clear_queue(&q);

    }while(op != 's' && op != 'S');

}
