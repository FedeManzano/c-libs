
#include "../comp_func.h"

int comp_p(const void *e1, const void *e2){
    t_producto * p1 = (t_producto *)e1;
    t_producto * p2 = (t_producto *)e2;
    return p1->cod - p2->cod;
}

int comp_cl(const void *e1,const void *e2)
{
    t_cliente * cl1 = (t_cliente *)e1;
    t_cliente * cl2 = (t_cliente *)e2;
    return cl1->dni - cl2->dni;
}


int comp_in(const void *e1,const void *e2)
{
    int * cl1 = (int *)e1;
    int * cl2 = (int *)e2;
    return *cl1 - *cl2;
}
