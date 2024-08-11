#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include "../libs/date.h"


int ingresar_valor_entero(const char *mje);
void limpiar();
void pausar();
char seleccionar_opcion(char * mje);
void ingresar_date(t_date *d);
void ingresar_time(t_date *d);
void mostrar_listado_fechas(t_date *fechas, const int ce);
void limpiar_mostrar_titulo(const char *mje);
int seleccionar_fecha_del_listado(const int ce);
void cargar_arreglo(int * arr, const int ce);
void mostrar_arreglo(int * arr, const int ce);
#endif // UTILS_H_INCLUDED
