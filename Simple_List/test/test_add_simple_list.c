#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_AddSimpleList_DiezElementos_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    for(int i = 0; i < 10; i ++)
        if(!is_full_simple_list(&l))
            add_simple_list(&l, &arr[i], sizeof(int));

    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"4 - test_AddSimpleList_DiezElementos_Resultado_Pass");
    clear_simple_list(&l);
}


void test_AddSimpleList_ListaNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int info = 2;
    int exp = _SIMPLE_LIST_NULL;
    int res = add_simple_list(NULL,&info,sizeof(int));
    it(&exp,&res,sizeof(int),comp_integer,"5 - test_AddSimpleList_ListaNula_Resultado_Pass");
}


void test_AddSimpleList_InfoNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int exp = _SIMPLE_LIST_INFO;
    int res = add_simple_list(&l,NULL,sizeof(int));
    it(&exp,&res,sizeof(int),comp_integer,"6 - test_AddSimpleList_InfoNula_Resultado_Pass");
}


void test_AddSimpleList_SizeMenorIgualCero_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int info = 2;
    int exp = _SIMPLE_LIST_SIZE;
    int res = add_simple_list(&l,&info,0);
    it(&exp,&res,sizeof(int),comp_integer,"7 - test_AddSimpleList_SizeMenorIgualCero_Resultado_Pass");
}



void test_AddSimpleList_TodosRepetidos_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,1,1,1,1,1,1,1,1,1};
    int exp[10] = {1,1,1,1,1,1,1,1,1,1};
    int res[10];

    for(int i = 0; i < 10; i ++)
        if(!is_full_simple_list(&l))
            add_simple_list(&l, &arr[i], sizeof(int));

    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"8 - test_AddSimpleList_TodosRepetidos_Resultado_Pass");
    clear_simple_list(&l);
}

