#ifndef COMP_FUNC_H_INCLUDED
#define COMP_FUNC_H_INCLUDED

typedef struct{
    int dni;
    char apyn[45];
}t_cliente;

typedef struct {
    int cod;
    char nombre[170];
    char cat[170];
    char tipo;
    float precio;
    int stock;
}t_producto;

int comp_p(const void *e1, const void *e2);

int comp_cl(const void *e1,const void *e2);

int comp_in(const void *e1,const void *e2);
int fil(const void *ele);
#endif // COMP_FUNC_H_INCLUDED
