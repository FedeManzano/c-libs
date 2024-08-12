#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include "../libs/date.h"
#include "../tree_module/pba_tree.h"

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
void dibujar(const void  *info, const int niv);
void dibujar_ind(const void  *info, const int niv);
int comp_in(const void  *e1, const void *e2);
int comp_ind(const void  *e1, const void *e2);
void lectura(const void *info_arbol, const void *info_arch, const long nreg);
void show_ele(const void * ele);
void leer_archivo();
void crear_archivo_prueba();
void saltos();


#endif // UTILS_H_INCLUDED
