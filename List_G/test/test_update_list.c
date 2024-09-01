#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include <time.h>
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_UpdateList_ActualizarElmentoDeLaLista_Resultado_Pass ()
{
    t_list l;
    init_list(&l);


    t_producto exp[10];
    t_producto res[10];
    t_producto p1;

    for(int i = 0; i < 10; i++)
    {
        p1.cod =  i + 1;
        strcpy(p1.nombre,"Nombre");
        strcpy(p1.cat,"Cat");
        p1.stock = 10;
        p1.precio = 2700.22;
        exp[i] = p1;
        add_list(&l,&p1,sizeof(t_producto));
    }

    p1.cod = 1;
    p1.stock = 10;
    update_list(&l,&p1,comp_p,up_prod);

    exp[0].stock = 20;
    to_array_list(&l,res,sizeof(t_producto));

    it_arr(exp,res,10,sizeof(t_producto),comp_p, "36 -> test_UpdateList_ActualizarElmentoDeLaLista_Resultado_Pass");
}
