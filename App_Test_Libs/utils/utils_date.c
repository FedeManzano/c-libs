#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void ingresar_date(t_date *d)
{
    if(!d)
        return;

    do{

        printf("Ingrese la fecha deseada(dd/mm/aaaa): \n");
        d->d = ingresar_valor_entero("Dia(1 - 29/30/31): ");
        d->m = ingresar_valor_entero("Mes(1 - 12): ");
        d->y = ingresar_valor_entero("Dia(1600 - Adelante): ");
        d->hh = 0;
        d->mm = 0;
        d->ss = 0;
        if(val_date(d->d,d->m,d->y) == DATE_ERROR)
            printf("\n\n ERROR En la validación de la fecha. Ingrese nuevamente\n\n");
    }while(val_date(d->d,d->m,d->y) == DATE_ERROR);

}


int seleccionar_fecha_del_listado(const int ce){
    int indF;

    do{

        indF = ingresar_valor_entero("Seleccione la fecha del listado: ");
        if(indF <= 0 || indF > ce)
            printf("Error en la seleccion. Ingrese nuevamente\n");
    }while(indF <= 0 || indF > ce);

    return indF;
}

void ingresar_time(t_date *d)
{
    if(!d)
        return;

    do{

        printf("Ingrese la fecha deseada(dd/mm/aaaa hh:mm:ss): \n");
        d->d = ingresar_valor_entero("Dia(1 - 29/30/31): ");
        d->m = ingresar_valor_entero("Mes(1 - 12): ");
        d->y = ingresar_valor_entero("Dia(1600 - Adelante): ");
        d->hh = ingresar_valor_entero("Horas(0 - 23): ");
        d->mm = ingresar_valor_entero("Minutos(0 - 59): ");
        d->ss = ingresar_valor_entero("Segundos(0 - 59): ");
        if(val_time(d->d,d->m,d->y,d->hh,d->mm,d->ss) == DATE_ERROR)
            printf("\n\n ERROR En la validación de la fecha. Ingrese nuevamente\n\n");
    }while(val_time(d->d,d->m,d->y,d->hh,d->mm,d->ss) == DATE_ERROR);

}


void mostrar_listado_fechas(t_date *fechas, const int ce){
    printf("Listado de Fechas \n");
    for(int i = 0; i < ce; i++){
        printf("%d - %s\n",i + 1, date_to_string(&fechas[i], DESCRIPTIVE_4));
    }
}
