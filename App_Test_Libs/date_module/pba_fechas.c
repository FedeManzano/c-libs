#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"
#include "../utils/utils.h"
#include "pba_fechas.h"


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

        op = seleccionar_opcion("\nDesea seguir agregando fechas: ");
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

        op = seleccionar_opcion("\nDesea seguir agregando fechas: ");
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

        printf("La diferencia es de (%ld) dias.\n\n", difference_days(&fechas[opF1 - 1],&fechas[opF2 - 1]));

        op = seleccionar_opcion("\nDesea seguir agregando fechas: ");
    }
    while(op == 'S' || op == 's');

}
