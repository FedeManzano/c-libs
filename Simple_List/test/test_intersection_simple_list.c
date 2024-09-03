#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"

void test_IntersectionSimpleList_InterseccionTresElementos_Resultado_Pass()
{
    t_simple_list l1, l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {10,20,30,5,40,50,80,90,3,100};

    int exp[3] = {10,5,3};
    int re[3];

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l1, &arr[i],sizeof(int));

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l2, &arr2[i],sizeof(int));

    t_simple_list res = intersection_simple_list(&l1,&l2,sizeof(int),comp_integer);

    to_array_simple_list(&res,re,sizeof(int));

    it_arr(exp,re,3,sizeof(int),comp_integer,"54 - test_IntersectionSimpleList_InterseccionTresElementos_Resultado_Pass");

    clear_simple_list(&l1);
    clear_simple_list(&l2);
    clear_simple_list(&res);
    free(res);
}


void test_IntersectionSimpleList_InterseccionNingunElemento_Resultado_Pass()
{
    t_simple_list l1, l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {20,30,40,50,60,70,80,90,100,110};

    int exp[3] = {};
    int re[3] = {};

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l1, &arr[i],sizeof(int));

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l2, &arr2[i],sizeof(int));

    t_simple_list res = intersection_simple_list(&l1,&l2,sizeof(int),comp_integer);

    to_array_simple_list(&res,re,sizeof(int));

    it_arr(exp,re,3,sizeof(int),comp_integer,"55 - test_IntersectionSimpleList_InterseccionNingunElemento_Resultado_Pass");

    clear_simple_list(&l1);
    clear_simple_list(&l2);
    clear_simple_list(&res);
    free(res);
}
