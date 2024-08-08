#ifndef COMP_INFO_TREE_SET_H_INCLUDED
#define COMP_INFO_TREE_SET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
// Indice de prueba para el arbol
typedef struct {
    int nro;
    char dni[15];
}t_ind;

typedef struct{
    long nro;
    int info;
}t_index;


void dibujar(const void  *info, const int niv);
int comp_i(const void *e1, const void *e2);
int comp_ind(const void *e1, const void *e2);
void show_i(const void *e);
int comp_s(const void *e1, const void *e2);
int comp_index(const void *e1, const void *e2);
void read_info(const void *info, const void *ia,const void *nro);
void dibujar_index(const void  *info, const int niv);
#endif // COMP_INFO_TREE_SET_H_INCLUDED
