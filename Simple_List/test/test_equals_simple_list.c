#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_EqualsList_CompararDosListasIguales_Resultado_Pass()
{
    t_simple_list l1;
    t_simple_list l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10]= {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
    {
        add_simple_list(&l1,&arr[i],sizeof(int));
        add_simple_list(&l2,&arr[i],sizeof(int));
    }

    int exp = _SIMPLE_LIST_EQUALS;
    int res = equals_simple_list(&l1,&l2,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"50 - test_EqualsList_CompararDosListasIguales_Resultado_Pass");
    clear_simple_list(&l1);
    clear_simple_list(&l2);
}


void test_EqualsList_CompararDosListasDistintoElUltimo_Resultado_Pass()
{
    t_simple_list l1;
    t_simple_list l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    int arr2[10]= {1,2,3,4,5,6,7,8,9,11};
    for(int i = 0; i < 10; i ++)
    {
        add_simple_list(&l1,&arr[i],sizeof(int));
        add_simple_list(&l2,&arr2[i],sizeof(int));
    }

    int exp = _SIMPLE_LIST_NO_EQUALS;
    int res = equals_simple_list(&l1,&l2,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"51 - test_EqualsList_CompararDosListasDistintoElUltimo_Resultado_Pass");
    clear_simple_list(&l1);
    clear_simple_list(&l2);
}


void test_EqualsList_CompararDosListasDistintoElPrimero_Resultado_Pass()
{
    t_simple_list l1;
    t_simple_list l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    int arr2[10]= {-1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i ++)
    {
        add_simple_list(&l1,&arr[i],sizeof(int));
        add_simple_list(&l2,&arr2[i],sizeof(int));
    }

    int exp = _SIMPLE_LIST_NO_EQUALS;
    int res = equals_simple_list(&l1,&l2,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"52 - test_EqualsList_CompararDosListasDistintoElPrimero_Resultado_Pass");
    clear_simple_list(&l1);
    clear_simple_list(&l2);
}


void test_EqualsList_CompararDosListasDistintoTamano_Resultado_Pass()
{
    t_simple_list l1;
    t_simple_list l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    int arr2[9]= {2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i ++)
    {
        add_simple_list(&l1,&arr[i],sizeof(int));
        add_simple_list(&l2,&arr2[i],sizeof(int));
    }

    int exp = _SIMPLE_LIST_NO_EQUALS;
    int res = equals_simple_list(&l1,&l2,comp_integer);

    it(&exp,&res,sizeof(int),comp_integer,"53 - test_EqualsList_CompararDosListasDistintoTamaño_Resultado_Pass");
    clear_simple_list(&l1);
    clear_simple_list(&l2);
}
