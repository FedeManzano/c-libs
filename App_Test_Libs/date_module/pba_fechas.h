#ifndef PBA_FECHAS_H_INCLUDED
#define PBA_FECHAS_H_INCLUDED

void pba_agregar_fecha (t_date *fechas, int * ce);
void pba_agregar_time (t_date *fechas, int * ce);
void pba_diferencia_en_dias(t_date *fechas, int ce);
void pba_diferencia_en_segundos(t_date *fechas, int ce);
void pba_ordenar_fechas(t_date *fechas, const int ce);
void pba_dia_de_la_semana();
#endif // PBA_FECHAS_H_INCLUDED
