#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include <it.h>


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
}


void test_PasarAArreglo_ArregloOrdenado_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];
    int arr[10] = {5,1,8,6,7,2,10,3,4,9};

    for(int i = 0; i < 10; i ++ )
        add_tree_set(&t,&arr[i],sizeof(int), comp_i);

    to_array_in_order(&t,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_i, "(3)-> test_PasarAArreglo_ArregloOrdenado_Resultado_Pass");
}



