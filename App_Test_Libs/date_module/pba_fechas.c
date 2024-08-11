#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"
#include "../utils/utils.h"
#include "pba_fechas.h"
#include "../libs/quicksort.h"


void pba_imprimir_titulo_listado_fechas (t_date *fechas, const int ce, const char *mje)
{
    limpiar_mostrar_titulo(mje);
    if(ce >= 1)
    {
        mostrar_listado_fechas(fechas,ce);
        printf("\n\n");
    }
}

void pba_agregar_fecha (t_date *fechas, int * ce)
{
    t_date fi;
    char op;
    do
    {
        pba_imprimir_titulo_listado_fechas(fechas,*ce,"Ingreso de fechas al listado\n\n");

        ingresar_date(&fi);
        fechas[*ce] = fi;
        (*ce) += 1;

        pba_imprimir_titulo_listado_fechas(fechas,*ce,"Ingreso de fechas al listado\n\n");

        op = seleccionar_opcion("\nDesea seguir agregando fechas ? (S/N): ");
    }
    while(op == 'S' || op == 's');
}


void pba_agregar_time (t_date *fechas, int * ce)
{
    t_date fi;
    char op;
    do
    {
        pba_imprimir_titulo_listado_fechas(fechas,*ce,"Ingreso de fechas al listado\n\n");

        ingresar_time(&fi);
        fechas[*ce] = fi;
        (*ce) += 1;

        pba_imprimir_titulo_listado_fechas(fechas,*ce,"Ingreso de fechas al listado\n\n");

        op = seleccionar_opcion("\nDesea seguir agregando fechas ? (S/N): ");
    }
    while(op == 'S' || op == 's');
}

void pba_diferencia_en_dias(t_date *fechas, int ce)
{
    char op;

    if(ce <= 0){
        pba_imprimir_titulo_listado_fechas(fechas,ce,"No hay fechas cargadas\n\n");
        pausar();
        return;
    }

    do
    {
        pba_imprimir_titulo_listado_fechas(fechas,ce,"Diferencia en dias entre fechas\n\n");

        int opF1 = seleccionar_fecha_del_listado(ce);
        int opF2 = seleccionar_fecha_del_listado(ce);

        pba_imprimir_titulo_listado_fechas(fechas,ce,"Ingreso de fechas al listado\n\n");

        long diff =  difference_days(&fechas[opF1 - 1],&fechas[opF2 - 1]);

        printf("La diferencia es de (%ld) dias.\n\n", diff);

        op = seleccionar_opcion("\nDesea seguir agregando fechas ?(S/N): ");
    }
    while(op == 'S' || op == 's');

}

void pba_diferencia_en_segundos(t_date *fechas, int ce)
{
    char op;

    if(ce <= 0){
        pba_imprimir_titulo_listado_fechas(fechas,ce,"No hay fechas cargadas\n\n");
        pausar();
        return;
    }

    do
    {
        pba_imprimir_titulo_listado_fechas(fechas,ce,"Diferencia en segundos entre fechas\n\n");

        int opF1 = seleccionar_fecha_del_listado(ce);
        int opF2 = seleccionar_fecha_del_listado(ce);

        pba_imprimir_titulo_listado_fechas(fechas,ce,"Ingreso de fechas al listado\n\n");

        printf("La diferencia es de (%lf) segundos.\n\n", difference_time(&fechas[opF1 - 1],&fechas[opF2 - 1]));

        op = seleccionar_opcion("\nDesea seguir calculando ?(S/N): ");
    }
    while(op == 'S' || op == 's');
}


void pba_ordenar_fechas(t_date *fechas, const int ce)
{
    char op;
    if(ce <= 0)
    {
        pba_imprimir_titulo_listado_fechas(fechas,ce,"No hay fechas cargadas\n\n");
        pausar();
        return;
    }

    pba_imprimir_titulo_listado_fechas(fechas,ce,"Ordenar Listado de Fechas\n\n");


    op = seleccionar_opcion("\nDesea ordenar la lista ?(S/N): ");

    if(op == 'S' || op == 's'){

        qs(fechas,ce,sizeof(t_date),comp_time);
        pba_imprimir_titulo_listado_fechas(fechas,ce,"Fechas Ordenadas\n\n");
        pausar();
    }
}

void pba_dia_de_la_semana()
{
    char op;
    t_date d;
    do{
        limpiar();
        printf("Calcular el nombre del dia de la semana\n\n");

        ingresar_date(&d);

        printf("\n\nEl dia de la semana es: %s\n", day_of_week(&d));

        op = seleccionar_opcion("\nDesea seguir calculando ?(S/N): ");

    }while(op == 'S' || op == 's');
}

void pba_agregar_x(t_date *fechas, const int ce, t_agregar a, const char *mje, char *unidad)
{
    char op;

    if(ce <= 0)
    {
        pba_imprimir_titulo_listado_fechas(fechas,ce,"No hay fechas cargadas\n\n");
        pausar();
        return;
    }
    do{
        pba_imprimir_titulo_listado_fechas(fechas,ce,mje);

        int sel = seleccionar_fecha_del_listado(ce);

        int valor = ingresar_valor_entero(unidad);

        a(&fechas[sel - 1],valor);

        pba_imprimir_titulo_listado_fechas(fechas,ce,mje);

        op = seleccionar_opcion("\nDesea continuar ?(S/N): ");

    }while(op == 'S' || op == 's');
}



void pba_ver_listado_fechas(t_date *fechas, const int ce)
{
    if(ce <= 0)
    {
        pba_imprimir_titulo_listado_fechas(fechas,ce,"No hay fechas cargadas\n\n");
        pausar();
        return;
    }

    pba_imprimir_titulo_listado_fechas(fechas,ce,"Ver listado de fechas \n\n");
    pausar();
}


void pba_ver_fecha_actual()
{
    limpiar();
    printf("Fecha actual es: %s\n\n", date_to_string(date_now(),DESCRIPTIVE_4));
    pausar();
}
