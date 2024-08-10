#ifndef PBA_FECHAS_H_INCLUDED
#define PBA_FECHAS_H_INCLUDED

typedef t_date * (*t_agregar)(t_date *d, int n);

void pba_agregar_fecha (t_date *fechas, int * ce);
void pba_agregar_time (t_date *fechas, int * ce);
void pba_diferencia_en_dias(t_date *fechas, int ce);
void pba_diferencia_en_segundos(t_date *fechas, int ce);
void pba_ordenar_fechas(t_date *fechas, const int ce);
void pba_dia_de_la_semana();
void pba_agregar_x(t_date *fechas, const int ce, t_agregar a, const char *mje, char *unidad);
void pba_ver_listado_fechas(t_date *fechas, const int ce);
void pba_ver_fecha_actual();
#endif // PBA_FECHAS_H_INCLUDED
