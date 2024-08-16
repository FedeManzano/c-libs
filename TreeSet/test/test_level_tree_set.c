#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include "../../bundle/it.h"



void test_NivelArbol_NievelDistintaDeCero_Resultado_Pass()
{
    t_tree_set t;
    init_tree_set(&t);

    int arr[10] = {5,3,10,1,7,4,6,9,2,8};

    for(int i = 0; i < 10; i ++)
        if(!is_full_tree_set(&t))
            add_tree_set(&t,&arr[i],sizeof(int),comp_i);

    int exp = 4;
    int res = level_tree_set(&t);

    it(&exp,&res,sizeof(int),comp_i,"(13)-> test_NivelArbol_NievelDistintaDeCero_Resultado_Pass");
    clear_tree_set(&t);
}


void test_NivelDelArbol_ArbolNulo_Resultado_Pass()
{
    t_tree_set t;
    init_tree_set(&t);


    int exp = -10;
    int res = level_tree_set(NULL);

    it(&exp,&res,sizeof(int),comp_i,"(14)-> test_NivelDelArbol_ArbolNulo_Resultado_Pass");
}


void test_Amplitude_Recorrido_Resultado_Pass()
{
    t_tree_set t;
    init_tree_set(&t);

    int arr[10] = {5,2,7,3,6,10,8,9,4,1};

    for(int i = 0; i < 10; i ++)
        if(!is_full_tree_set(&t))
            add_tree_set(&t,&arr[i],sizeof(int),comp_i);

    amplitude_tree_set(&t,show_i);
}

