#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_IndexOfSimpleList_IndexDeUnElementoDentro_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {20,30,40,50,60,70,80,90,100};
    int info = 50;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);


    int exp = 3;
    int res = index_of_simple_list(&l,&info,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"40 - test_IndexOfSimpleList_IndexDeUnElementoDentro_Resultado_Pass");
    clear_simple_list(&l);
}


void test_IndexOfSimpleList_IndexDeUnNoEstaEnLaLista_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {20,30,40,50,60,70,80,90,100};
    int info = 110;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);


    int exp = -1;
    int res = index_of_simple_list(&l,&info,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"41 - test_IndexOfSimpleList_IndexDeUnNoEstaEnLaLista_Resultado_Pass");
    clear_simple_list(&l);
}


void test_IndexOfSimpleList_IndexDeListaNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {20,30,40,50,60,70,80,90,100};
    int info = 50;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);


    int exp = -1;
    int res = index_of_simple_list(NULL,&info,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"42 - test_IndexOfSimpleList_IndexDeListaNula_Resultado_Pass");
    clear_simple_list(&l);
}



void test_IndexOfSimpleList_IndexDeInfoNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {20,30,40,50,60,70,80,90,100};
    int info = 50;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);


    int exp = -1;
    int res = index_of_simple_list(&l,NULL,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"43 - test_IndexOfSimpleList_IndexDeInfoNula_Resultado_Pass");
    clear_simple_list(&l);
}
