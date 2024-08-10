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
        if(val_date(d->d,d->m,d->y) == DATE_ERROR)
            printf("\n\n ERROR En la validación de la fecha. Ingrese nuevamente\n\n");
    }while(val_date(d->d,d->m,d->y) == DATE_ERROR);

}

void mostrar_listado_fechas(t_date *fechas, const int ce){
    printf("Listado de Fechas \n");
    for(int i = 0; i < ce; i++){
        printf("%d - %s\n",i + 1, date_to_string(&fechas[i], DESCRIPTIVE_4));
    }
}
