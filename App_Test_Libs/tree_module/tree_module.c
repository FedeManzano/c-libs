#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"
#include "../utils/utils.h"
#include "pba_tree.h"



void mostrar_module_tree()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDEFGHIJKLMOPS",
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
        "Podar Hojas",
        "Indexar archivo binario ordenado",
        "Recorrer En Amplitud",
        "Salir"
    };

    t_tree_set t;

    init_tree_set(&t);

    t_menu menu;
    init_menu(&menu, opciones,"TDA Arbol Binario");

    crear_archivo_prueba();

    char op;

    do{

        op = get_option(&menu);

        switch(op)
        {
            case 'A': pba_ingresar_elemento_arbol(&t);
                break;
            case 'B': pba_cantidad_nodos_arbol(&t);
                break;
            case 'C': pba_altura_arbol(&t);
                break;
            case 'D': pba_rec(&t,in_order_tree_set,"Recorrido En Orden\n\n");
                break;
            case 'E': pba_rec(&t,pre_order_tree_set,"Recorrido En Pre-Orden\n\n");
                break;
            case 'F': pba_rec(&t,post_order_tree_set,"Recorrido En Post-Orden\n\n");
                break;
            case 'G': pba_nivel_arbol(&t);
                break;
            case 'H': pba_niveles_info_arbol(&t);
                break;
            case 'I': pba_un_nivel_completo(&t);
                break;
            case 'J': pba_eliminar_elemento(&t);
                break;
            case 'K': pba_mostrar_arbol(&t);
                break;
            case 'L': pba_mostrar_hojas(&t);
                break;
            case 'M': pba_podar_hojas(&t);
                break;
            case 'O': pba_crear_index_archivo();
                break;
            case 'P': pba_rec(&t,amplitude_tree_set,"Recorrido En Amplitud\n\n");
                break;
        }

        if(!is_empty_tree_set(&t) && (op == 'S' || op == 's'))
        {
            printf("\n\nHay elementos guardadas. Si sale pierde lo realizado.\n");
            char o = seleccionar_opcion("Desea salir y perder los cambios ? (S/N): ");
            if(o != 's' && o != 'S')
                op = '\0';
        } else if(op == 'S' || op == 's')
            clear_tree_set(&t);

    }while(op != 's' && op != 'S');

}
