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
    init_menu(&menu, opciones,"TDA Cola");
    init_queue(&q);
    char op;

    do{

        op = get_option(&menu);

        switch(op)
        {

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
