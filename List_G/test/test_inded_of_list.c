#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_IndexOfList_BuscarIndexDeElementoExistente_resultado_Pass()
{
    t_list l;
    init_list(&l);
    int exp = 2;
    int res;
    int info = 3;
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    res = index_of_list(&l,&info,sizeof(int),comp_in);

    it(&exp,&res,sizeof(int),comp_in,"(30)-> test_IndexOfList_BuscarIndexDeElementoExistente_resultado_Pass");
    clear_list(&l);
}


void test_IndexOfList_BuscarIndexDeElementoNoExistente_resultado_Pass()
{
    t_list l;
    init_list(&l);
    int exp = -1;
    int res;
    int info = 6;
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    res = index_of_list(&l,&info,sizeof(int),comp_in);

    it(&exp,&res,sizeof(int),comp_in,"(31)-> test_IndexOfList_BuscarIndexDeElementoNoExistente_resultado_Pass");
    clear_list(&l);
}
