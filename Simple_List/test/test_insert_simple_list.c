#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_InsertSimpleList_InsertarElementoEnUnaListaVacia_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int info = 2;
    insert_simple_list(&l,&info,sizeof(int), 10); // Lo inserta al final

    int exp = 1;
    int res = len_simple_list(&l);

    it(&exp,&res,sizeof(int),comp_integer,"27 - test_InsertSimpleList_InsertarElementoEnUnaListaVacia_Resultado_Pass");
    clear_simple_list(&l);
}


void test_InsertSimpleList_InsertarEnListaNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int info = 2;
    int res = insert_simple_list(NULL,&info,sizeof(int), 10); // Lo inserta al final

    int exp = _SIMPLE_LIST_NULL;

    it(&exp,&res,sizeof(int),comp_integer,"28 - test_InsertSimpleList_InsertarEnListaNula_Resultado_Pass");
    clear_simple_list(&l);
}


void test_InsertSimpleList_InsertarConInfoNula_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int info = 2;
    int res = insert_simple_list(&l,NULL,sizeof(int), 10); // Lo inserta al final

    int exp = _SIMPLE_LIST_INFO;

    it(&exp,&res,sizeof(int),comp_integer,"29 - test_InsertSimpleList_InsertarConInfoNula_Resultado_Pass");
    clear_simple_list(&l);
}


void test_InsertSimpleList_InsertarVariosElementos_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    for(int i = 0; i < 10; i ++)
        insert_simple_list(&l,&arr[i],sizeof(int),i);

    to_array_simple_list(&l,res,sizeof(int));


    it_arr(exp,res,10,sizeof(int),comp_integer,"30 - test_InsertSimpleList_InsertarVariosElementos_Resultado_Pass");
    clear_simple_list(&l);
}


void test_InsertSimpleList_InsertarUnRangoDeElementos_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    to_array_simple_list(&l,res,sizeof(int));


    it_arr(exp,res,10,sizeof(int),comp_integer,"31 - test_InsertSimpleList_InsertarUnRangoDeElementos_Resultado_Pass");
    clear_simple_list(&l);
}

void test_InsertSimpleList_InsertarUnRangoDeElementosConIndexUno_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    insert_range_simple_list(&l,arr,sizeof(int),10,1);

    to_array_simple_list(&l,res,sizeof(int));


    it_arr(exp,res,10,sizeof(int),comp_integer,"32 - test_InsertSimpleList_InsertarUnRangoDeElementosConIndexUno_Resultado_Pass");
    clear_simple_list(&l);
}
