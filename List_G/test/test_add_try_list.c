#include <stdio.h>
#include <stdlib.h>
#include "it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"



void test_AddListTryListO_ListaNula_MenosDiez_ResultadoPass()
{
    int p = 0;
    int exp = LIST_NULL;
    int res = try_add_list_o(NULL,&p,sizeof(int),comp_in);

    it(&exp,&res,sizeof(int),comp_in,"(9)-> test_AddListTryListO_ListaNula_MenosDiez_ResultadoPass");
}


void test_TryAddListO_InfoNula_MenosNueve_ResultadoPass()
{
    t_list l;
    init_list(&l);

    int exp = ERROR_INFO;
    int res = try_add_list_o(&l,NULL,sizeof(int),comp_in);
    it(&exp,&res,sizeof(int),comp_in,"(10)-> test_TryAddListO_InfoNula_MenosNueve_ResultadoPass");
}

void test_TryAddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[5] = {1,2,3,4,5};
    int res[5];
    int arr[5] = {3,1,2,5,4};
    for(int i = 0; i < 5; i++)
        try_add_list_o(&l,&arr[i],sizeof(int),comp_in);
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,5,sizeof(int),comp_in,"(11)-> test_TryAddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass");
    clear_list(&l);
}

void test_TryAddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[1] = {1};
    int res[1];
    int arr[5] = {1,1,1,1,1};
    for(int i = 0; i < 5; i++)
        try_add_list_o(&l,&arr[i],sizeof(int),comp_in);
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,1,sizeof(int),comp_in,"(12)-> test_TryAddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass");
    clear_list(&l);
}


void test_TryAddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[4] = {1,2,3,4};
    int res[4];
    int arr[5] = {1,2,3,4,1};
    for(int i = 0; i < 5; i++)
        try_add_list_o(&l,&arr[i],sizeof(int),comp_in);

    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,4,sizeof(int),comp_in,"(13)-> test_TryAddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass");
    clear_list(&l);
}


void test_TryAddListO_Agregar5DosRepetidos_ConservaLaUltimaClave_ResultadoPass()
{
    t_list l;
    init_list(&l);
    t_cliente res[4];
    t_cliente arr[5] = {
        {25111222,"Primer Clave"},
        {20111222, "Adjunto1"},
        {25111222,"Segunda clave"},
        {20111226, "Adjunto2"},
        {20111228, "Adjunto3"},
    };

    t_cliente exp[4] = {
        {20111222, "Adjunto1"},
        {20111226, "Adjunto2"},
        {20111228, "Adjunto3"},
        {25111222,"Segunda clave"},
    };

    for(int i = 0; i < 5; i++)
        try_add_list_o(&l,&arr[i],sizeof(t_cliente),comp_in);
    to_array_list(&l,res,sizeof(t_cliente));

    it_arr(exp,res,4,sizeof(t_cliente),comp_cl,"(14)-> test_TryAddListO_Agregar5DosRepetidos_ConservaLaUltimaClave_ResultadoPass");
    clear_list(&l);
}
