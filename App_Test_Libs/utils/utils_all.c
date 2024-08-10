#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void limpiar(){
    system("cls");
}

void pausar(){
    system("pause");
}

int ingresar_valor_entero(const char *mje)
{
    int valor = 0;
    printf(mje);
    fflush(stdin);
    scanf("%d", &valor);
    return valor;
}

char seleccionar_opcion(char * mje)
{
    char valor;
    printf(mje);
    fflush(stdin);
    scanf("%c", &valor);
    return valor;
}

void limpiar_mostrar_titulo(const char *mje)
{
    limpiar();
    printf(mje);
}
