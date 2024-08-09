#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include <it.h>


void test_ContarHojas_HojasDistintoCero_Resultado_Pass()
{
    t_tree_set t;
    init_tree_set(&t);

    int arr[10] = {5,3,10,1,7,4,6,9,2,8};

    for(int i = 0; i < 10; i ++)
        if(!is_full_tree_set(&t))
            add_tree_set(&t,&arr[i],sizeof(int),comp_i);

    int exp = 4;
    int res = count_leaf_tree_set(&t);

    it(&exp,&res,sizeof(int),comp_i,"(15)-> test_ContarHojas_HojasDistintoCero_Resultado_Pass");
    clear_tree_set(&t);
}


void test_ContarHojas_ArbolNulo_Resultado_Pass()
{
    t_tree_set t;
    init_tree_set(&t);

    int exp = -10;
    int res = count_leaf_tree_set(NULL);

    it(&exp,&res,sizeof(int),comp_i,"(16)-> test_ContarHojas_HojasCero_Resultado_Pass");
    clear_tree_set(&t);
}
