#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"



void test_SortSimpleList_OrdenarDiezElementos_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    insert_range_simple_list(&l,arr,sizeof(int),10,0);



    sort_simple_list(&l,sizeof(int),comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"33 - test_SortSimpleList_OrdenarDiezElementos_Resultado_Pass");
    clear_simple_list(&l);
}


void test_SortSimpleList_ListaNula_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int exp[10] = {10,9,8,7,6,5,4,3,2,1};
    int res[10];

    insert_range_simple_list(&l,arr,sizeof(int),10,0);



    sort_simple_list(NULL,sizeof(int),comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"34 - test_SortSimpleList_ListaNula_Resultado_Pass");
    clear_simple_list(&l);
}


void test_SortSimpleList_TamMenorIgualACero_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int exp[10] = {10,9,8,7,6,5,4,3,2,1};
    int res[10];

    insert_range_simple_list(&l,arr,sizeof(int),10,0);



    sort_simple_list(NULL,0,comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"35 - test_SortSimpleList_TamMenorIgualACero_Resultado_Pass");
    clear_simple_list(&l);
}
