#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"

void test_EstaVacia_Verdadero_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int exp = 1;
    int res = is_empty_simple_list(&l) ? 1 : 0;
    it(&exp,&res,sizeof(int),comp_integer,"1 - test_EstaVacia_Verdadero_Resultado_Pass");
}

void test_EstaVacia_False_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int info = 3;
    add_simple_list(&l,&info, sizeof(int));
    int exp = 0;
    int res = is_empty_simple_list(&l) ? 1 : 0;
    it(&exp,&res,sizeof(int),comp_integer,"2 - test_EstaVacia_False_Resultado_Pass");
}
