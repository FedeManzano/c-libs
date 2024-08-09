#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include <it.h>


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


void test_AgregarElementos_UnSoloElementoPorRepetidos_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int exp[1] = {1};
    int res[1];
    int arr[10] = {1,1,1,1,1,1,1,1,1,1};

    for(int i = 0; i < 10; i ++ )
        add_tree_set(&t, &arr[i], sizeof(int), comp_i);

    to_array_in_order(&t,res,sizeof(int));

    it_arr(exp,res,1,sizeof(int),comp_i, "(4)-> test_AgregarElementos_UnSoloElementoPorRepetidos_Resultado_Pass");
}



void test_AgregarElementos_InfoNulaMenosNueve_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int res = add_tree_set(&t,NULL,sizeof(int),comp_i);
    int exp = -9;

    it(&exp,&res,sizeof(int),comp_i, "(5)-> test_AgregarElementos_InfoNulaMenosNueve_Resultado_Pass");
    clear_tree_set(&t);
}


void test_AgregarElementos_TamDatoInvalidoMenosocho_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);
    int in;
    int res = add_tree_set(&t,&in,0,comp_i);
    int exp = -8;

    it(&exp,&res,sizeof(int),comp_i, "(6)-> test_AgregarElementos_TamDatoInvalidoMenosocho_Resultado_Pass");
    clear_tree_set(&t);
}


