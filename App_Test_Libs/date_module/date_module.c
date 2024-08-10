#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"


void mostrar_module_date()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDEFGHIJKLS",
        "Agregar Fecha (dd/mm/aaaa)",
        "Agregar Fecha (dd/mm/aaaa hh:mm:ss)",
        "Diferencia En Dias",
        "Diferencia en Segundos"
        "Ordenar Fechas",
        "Dia de la Semana",
        "Agregar / Restar Dias a una Fecha",
        "Agregar / Restar Horas a una Fecha",
        "Agregar / Restar Minutos a una Fecha",
        "Agregar / Restar Segundos a una Fecha",
        "Ver Listado de Fechas",
        "Fecha Actual",
        "salir"
    };
    t_menu menu;
    init_menu(&menu, opciones,"TDA Fechas");

    char op;

    do{

        op = get_option(&menu);


    }while(op == 's' || op == 'S');

}
