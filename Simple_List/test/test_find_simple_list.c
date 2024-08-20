#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"




void test_FindSimpleList_ElementoEncontrado_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp = _SIMPLE_LIST_OK;
    int info = 10;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    int res = find_simple_list(&l,&info,sizeof(int), comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"44 - test_FindSimpleList_ElementoEncontrado_Resultado_Pass");
    clear_simple_list(&l);

}


void test_FindSimpleList_ElementoNoEncontrado_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp = _SIMPLE_LIST_NO_FIND;
    int info = 110;

    insert_range_simple_list(&l,arr,sizeof(int),10,0);

    int res = find_simple_list(&l,&info,sizeof(int), comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"45 - test_FindSimpleList_ElementoNoEncontrado_Resultado_Pass");
    clear_simple_list(&l);

}
