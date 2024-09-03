#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_SubSimpleList_CrearSublistaDe5Elementos_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int exp[5] = {1,2,3,4,5};
    int res[5];

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l,&arr[i],sizeof(int));

    t_simple_list l2 = sub_simple_list(&l,sizeof(int),0,4);

    to_array_simple_list(&l2,res,sizeof(int));

    it_arr(exp,res,5,sizeof(int),comp_integer,"47 - test_SubSimpleList_CrearSublistaDe5Elementos_Resultado_Pass");
    clear_simple_list(&l);
    clear_simple_list(&l2);
}


void test_SubSimpleList_StartNegativo_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l,&arr[i],sizeof(int));

    t_simple_list l2 = sub_simple_list(&l,sizeof(int),-1,4);

    it(NULL,l2,sizeof(t_simple_list),comp_integer,"48 - test_SubSimpleList_StartNegativo_Resultado_Pass");
}


void test_SubSimpleList_EndNegativo_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l,&arr[i],sizeof(int));

    t_simple_list l2 = sub_simple_list(&l,sizeof(int),0,-1);

    it(NULL,l2,sizeof(t_simple_list),comp_integer,"49 - test_SubSimpleList_EndNegativo_Resultado_Pass");
}
