#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"
#include "pba_fechas.h"



void mostrar_module_date()
{
    char opciones [TAM_MENU][TAM_MENU] =
    {
        "ABCDEFGHIJKLS",
        "Agregar Fecha (dd/mm/aaaa)",
        "Agregar Fecha (dd/mm/aaaa hh:mm:ss)",
        "Diferencia En Dias",
        "Diferencia en Segundos",
        "Ordenar Fechas",
        "Dia de la Semana",
        "Agregar / Restar Dias a una Fecha",
        "Agregar / Restar Horas a una Fecha",
        "Agregar / Restar Minutos a una Fecha",
        "Agregar / Restar Segundos a una Fecha",
        "Ver Listado de Fechas",
        "Fecha Actual",
        "Salir"
    };
    t_menu menu;
    init_menu(&menu, opciones,"TDA Fechas");

    t_date fechas[100];
    int ce = 0;

    char op;

    do{

        op = get_option(&menu);

        switch(op){
            case 'A': pba_agregar_fecha(fechas, &ce);
                break;
            case 'B': pba_agregar_time(fechas, &ce);
                break;
            case 'C': pba_diferencia_en_dias(fechas, ce);
                break;
            case 'D': pba_diferencia_en_segundos(fechas, ce);
                break;
             case 'E': pba_ordenar_fechas(fechas, ce);
                break;
            case 'F': pba_dia_de_la_semana();
                break;
            case 'G': pba_agregar_x(fechas,ce,add_days,"Agregar / Restar Dias\n\n","Ingresar la cantidad de dias(suma + / resta -): ");
                break;
            case 'H': pba_agregar_x(fechas,ce,add_hours,"Agregar / Restar Horas\n\n","Ingresar la cantidad de horas(suma + / resta -): ");
                break;
            case 'I': pba_agregar_x(fechas,ce,add_minutes,"Agregar / Restar Minutos\n\n","Ingresar la cantidad de minutos(suma + / resta -): ");
                break;
            case 'J': pba_agregar_x(fechas,ce,add_seconds,"Agregar / Restar Segundos\n\n","Ingresar la cantidad de segundos(suma + / resta -): ");
                break;
            case 'K': pba_ver_listado_fechas(fechas,ce);
                break;
            case 'L': pba_ver_fecha_actual();
                break;
        }
    }while(op != 's' && op != 'S');

}
