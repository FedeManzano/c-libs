#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include "../libs/date.h"


int ingresar_valor_entero(const char *mje);
void limpiar();
void pausar();
char seleccionar_opcion(char * mje);
void ingresar_date(t_date *d);
void mostrar_listado_fechas(t_date *fechas, const int ce);
void limpiar_mostrar_titulo(const char *mje);



#endif // UTILS_H_INCLUDED
