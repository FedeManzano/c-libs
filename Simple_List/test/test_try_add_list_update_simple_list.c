#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"



void test_tryAddUpdateSimpleListInOrderUpdate_DiezElementos_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    for(int i = 0; i < 10; i ++)
        if(!is_full_simple_list(&l))
            try_add_simple_list_in_order_update(&l, &arr[i], sizeof(int),comp_integer,update);

    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"19 - test_tryAddUpdateSimpleListInOrderUpdate_DiezElementos_Resultado_Pass");
    clear_simple_list(&l);
}


void test_TryAddSimpleListEnOrdenUpdate_ListaNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int info = 2;
    int exp = _SIMPLE_LIST_NULL;
    int res = try_add_simple_list_in_order_update(NULL,&info,sizeof(int),comp_integer,update);
    it(&exp,&res,sizeof(int),comp_integer,"20 - test_TryAddSimpleListEnOrdenUpdate_ListaNula_Resultado_Pass");
}


void test_TryAddSimpleListEnOrdenUpdate_InfoNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int exp = _SIMPLE_LIST_INFO;
    int res = try_add_simple_list_in_order_update(&l,NULL,sizeof(int), comp_integer,update);
    it(&exp,&res,sizeof(int),comp_integer,"21 - test_TryAddSimpleListEnOrdenUpdate_InfoNula_Resultado_Pass");
}


void test_TryAddSimpleListEnOrdenUpdate_SizeMenorIgualCero_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int info = 2;
    int exp = _SIMPLE_LIST_SIZE;
    int res = try_add_simple_list_in_order_update(&l,&info,0,comp_integer,update);
    it(&exp,&res,sizeof(int),comp_integer,"22 - test_TryAddSimpleListEnOrdenUpdate_SizeMenorIgualCero_Resultado_Pass");
}



void test_TryAddSimpleListEnOrdenUpdate_TodosRepetidos_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,1,1,1,1,1,1,1,1,1};
    int exp[5] = {2,2,2,2,2};
    int res[5];

    for(int i = 0; i < 10; i ++)
        if(!is_full_simple_list(&l))
            try_add_simple_list_in_order_update(&l, &arr[i], sizeof(int),comp_integer,update);

    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,5,sizeof(int),comp_integer,"23 - test_TryAddSimpleListEnOrdenUpdate_TodosRepetidos_Resultado_Pass");
    clear_simple_list(&l);
}

