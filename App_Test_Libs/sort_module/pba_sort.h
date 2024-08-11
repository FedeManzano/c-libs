#ifndef PBA_SORT_H_INCLUDED
#define PBA_SORT_H_INCLUDED

typedef int (*t_comp)(const void *, const void *);
typedef void (*t_sort)(void *,const int,size_t, t_comp);
void pba_ordenar_seleccion(t_sort ordenar, const char *mje);
void pba_qs_vs_sel ();
#endif // PBA_SORT_H_INCLUDED
