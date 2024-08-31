#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"



void test_LenSinpleList_ListaVacia_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int exp = 0;
    int res = len_simple_list(&l);

    it(&exp,&res,sizeof(int), comp_integer,"24 - test_LenSinpleList_ListaVacia_Resultado_Pass");
}


void test_LenSinpleList_ListaNula_Resultado_Pass ()
{
    int exp = -10;
    int res = len_simple_list(NULL);


    it(&exp,&res,sizeof(int), comp_integer,"25 - test_LenSinpleList_ListaNula_Resultado_Pass");
}


void test_LenSinpleList_UnElemento_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int info = 1;
    add_simple_list(&l,&info,sizeof(int));
    int exp = 1;
    int res = len_simple_list(&l);
    it(&exp,&res,sizeof(int), comp_integer,"26 - test_LenSinpleList_UnElemento_Resultado_Pass");
}
