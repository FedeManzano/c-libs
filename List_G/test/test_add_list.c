#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"



void test_AddList_ListaNula_MenosDiez_ResultadoPass()
{
    int p = 0;
    int exp = LIST_NULL;
    int res = add_list(NULL,&p,sizeof(int));

    it(&exp,&res,sizeof(int),comp_in,"(20)-> test_AddList_ListaNula_MenosDiez_ResultadoPass");
}

void test_AddList_InfoNula_MenosNueve_ResultadoPass()
{
    t_list l;
    init_list(&l);

    int exp = ERROR_INFO;
    int res = add_list(&l,NULL,sizeof(int));
    it(&exp,&res,sizeof(int),comp_in,"(21)-> test_AddList_ListaNula_MenosDiez_ResultadoPass");
}


void test_AddFirstList_Agregar5ElementosSinRepetir_CompCola_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[5] = {5,4,3,2,1};
    int res[5];
    int arr[5] = {5,4,3,2,1};
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,5,sizeof(int),comp_in,"(22)-> test_AddFirstList_Agregar5ElementosSinRepetir_CompCola_ResultadoPass");
    clear_list(&l);
}


void test_AddList_Agregar5ElementosTodosRepetidos_SeMantienenTodos_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[5] = {1,1,1,1,1};
    int res[5];
    int arr[5] = {1,1,1,1,1};
    for(int i = 0; i < 5; i++)
        add_list(&l,&arr[i],sizeof(int));
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,5,sizeof(int),comp_in,"(23)-> test_AddList_Agregar5ElementosTodosRepetidos_SeMantienenTodos_ResultadoPass");
    clear_list(&l);
}
