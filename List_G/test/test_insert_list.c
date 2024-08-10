#include <stdio.h>
#include <stdlib.h>
#include "it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"

void test_InsertList_InsertarUnElementoAlInicio_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[6] = {8,1,2,3,4,5};
    int res[6];
    int arr[5] = {1,2,3,4,5};
    int ele = 8;
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    insert_list(&l,&ele,sizeof(int),0);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,6,sizeof(int),comp_in,"(24)-> test_InsertList_InsertarUnElementoAlInicio_Resultado_Pass");
    clear_list(&l);
}


void test_InsertList_InsertarUnElementoAlFinal_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[6] = {1,2,3,4,5,8};
    int res[6];
    int arr[5] = {1,2,3,4,5};
    int ele = 8;
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    insert_list(&l,&ele,sizeof(int),10);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,6,sizeof(int),comp_in,"(25)-> test_InsertList_InsertarUnElementoAlFinal_Resultado_Pass");
    clear_list(&l);
}


void test_InsertList_InsertarUnElementoEnLaPos2_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[6] = {1,2,8,3,4,5};
    int res[6];
    int arr[5] = {1,2,3,4,5};
    int ele = 8;
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    insert_list(&l,&ele,sizeof(int),2);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,6,sizeof(int),comp_in,"(26)-> test_InsertList_InsertarUnElementoEnLaPos2_Resultado_Pass");
    clear_list(&l);
}


void test_InsertList_InsertarUnElementoEnLaPos1_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[6] = {1,8,2,3,4,5};
    int res[6];
    int arr[5] = {1,2,3,4,5};
    int ele = 8;
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    insert_list(&l,&ele,sizeof(int),1);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,6,sizeof(int),comp_in,"(27)-> test_InsertList_InsertarUnElementoEnLaPos1_Resultado_Pass");
    clear_list(&l);
}


void test_InsertList_InsertarUnElementoEnLaPenultima_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[6] = {1,2,3,8,4,5};
    int res[6];
    int arr[5] = {1,2,3,4,5};
    int ele = 8;
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));

    insert_list(&l,&ele,sizeof(int),3);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,6,sizeof(int),comp_in,"(28)-> test_InsertList_InsertarUnElementoEnLaPenultima_Resultado_Pass");
    clear_list(&l);
}


void test_InsertList_InsertarelementosEnListaVacia_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[5] = {1,2,3,4,5};
    int res[5];
    int arr[5] = {1,2,3,4,5};

    for(int i = 0; i < 5; i++)
        insert_list(&l,&arr[i],sizeof(int),i);


    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,5,sizeof(int),comp_in,"(29)-> test_InsertList_InsertarelementosEnListaVacia_Resultado_Pass");
    clear_list(&l);
}


void test_InsertRangeList_InsertaUnRangoDe5Elementos_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[5] = {1,2,3,4,5};
    int res[5];
    int arr[5] = {1,2,3,4,5};

    insert_range_list(&l,arr,5,sizeof(int),0);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,5,sizeof(int),comp_in,"(32)-> test_InsertRangeList_InsertaUnRangoDe5Elementos_Resultado_Pass");
    clear_list(&l);
}


void test_InsertRangeList_InsertaUnRangoDe2Elementos_Resultado_Pass () {
    t_list l;
    init_list(&l);

    int exp[5] = {3,4};
    int res[5];
    int arr[5] = {3,4};

    insert_range_list(&l,arr,2,sizeof(int),0);

    to_array_list(&l,res,sizeof(int));


    it_arr(exp,res,2,sizeof(int),comp_in,"(33)-> test_InsertRangeList_InsertaUnRangoDe2Elementos_Resultado_Pass");
    clear_list(&l);
}
