#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include "../../bundle/it.h"


void test_ArbolVacio_Verdadero_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);
    int exp = 1;
    int res = is_empty_tree_set(&t) > 0 ? 1: 0;
    it(&exp,&res,sizeof(int),comp_i, "(1)-> test_ArbolVacio_Verdadero_Resultado_Pass");
}

void test_ArbolNoVacio_Falso_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int test_info = 0;

    add_tree_set(&t,&test_info,sizeof(int),comp_i);

    int exp = 0;
    int res = is_empty_tree_set(&t) > 0 ? 1: 0;
    it(&exp,&res,sizeof(int),comp_i, "(2)-> test_ArbolNoVacio_Falso_Resultado_Pass");
    clear_tree_set(&t);
}




