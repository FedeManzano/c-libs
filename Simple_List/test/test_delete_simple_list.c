#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_DeleteSimpleList_EliminarElementoListaDeDiez_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp[9] = {1,2,3,4,5,7,8,9,10};
    int res[9];

    int del = 6;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    delete_simple_list(&l,&del,sizeof(int),comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,9,sizeof(int),comp_integer,"36 - test_DeleteSimpleList_EliminarElementoListaDeDiez_Resultado_Pass");
    clear_simple_list(&l);
}


void test_DeleteSimpleList_EliminarElementoDelFinal_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp[9] = {1,2,3,4,5,6,7,8,9};
    int res[9];

    int del = 10;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    delete_simple_list(&l,&del,sizeof(int),comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,9,sizeof(int),comp_integer,"37 - test_DeleteSimpleList_EliminarElementoDelFinal_Resultado_Pass");
    clear_simple_list(&l);
}


void test_DeleteSimpleList_EliminarElementoDelInicio_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp[9] = {2,3,4,5,6,7,8,9,10};
    int res[9];

    int del = 1;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    delete_simple_list(&l,&del,sizeof(int),comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,9,sizeof(int),comp_integer,"38 - test_DeleteSimpleList_EliminarElementoDelInicio_Resultado_Pass");
    clear_simple_list(&l);
}


void test_DeleteSimpleList_EliminarElementoYDuplicados_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,1,5,6,7,1,9,1};
    int exp[6] = {2,3,5,6,7,9};
    int res[6];

    int del = 1;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    delete_all_simple_list(&l,&del,sizeof(int),comp_integer);


    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,6,sizeof(int),comp_integer,"39 - test_DeleteSimpleList_EliminarElementoYDuplicados_Resultado_Pass");
    clear_simple_list(&l);
}

