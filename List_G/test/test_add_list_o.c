#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"

/** \brief
 *  Intenta agregar un elemento con una lista nula de parámetro.
 *  El resultado de esta prueba es -10 ERR por lista nula.
 * \return void
 *
 */
void test_AddListO_ListaNula_MenosDiez_ResultadoPass()
{
    int p = 0;
    int exp = LIST_NULL;
    int res = add_list_o(NULL,&p,sizeof(int),comp_in);

    it(&exp,&res,sizeof(int),comp_in,"(3)-> test_AddListO_ListaNula_MenosDiez_ResultadoPass");
}

void test_AddListO_InfoNula_MenosNueve_ResultadoPass()
{
    t_list l;
    init_list(&l);

    int exp = ERROR_INFO;
    int res = add_list_o(&l,NULL,sizeof(int),comp_in);
    it(&exp,&res,sizeof(int),comp_in,"(4)-> test_AddListO_InfoNula_MenosNueve_ResultadoPass");
}


void test_AddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[5] = {1,2,3,4,5};
    int res[5];
    int arr[5] = {3,1,2,5,4};
    for(int i = 0; i < 5; i++)
        add_list_o(&l,&arr[i],sizeof(int),comp_in);
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,5,sizeof(int),comp_in,"(5)-> test_AddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass");
}


void test_AddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[1] = {1};
    int res[1];
    int arr[5] = {1,1,1,1,1};
    for(int i = 0; i < 5; i++)
        add_list_o(&l,&arr[i],sizeof(int),comp_in);
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,1,sizeof(int),comp_in,"(6)-> test_AddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass");
    clear_list(&l);
}

void test_AddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass()
{
    t_list l;
    init_list(&l);
    int exp[4] = {1,2,3,4};
    int res[4];
    int arr[5] = {1,2,3,4,1};
    for(int i = 0; i < 5; i++)
        add_list_o(&l,&arr[i],sizeof(int),comp_in);
    to_array_list(&l,res,sizeof(int));
    it_arr(exp,res,4,sizeof(int),comp_in,"(7)-> test_AddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass");
    clear_list(&l);
}

void test_AddListO_Agregar5DosRepetidos_ConservaLaPrimerClave_ResultadoPass()
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
        {25111222,"Primer Clave"},
    };

    for(int i = 0; i < 5; i++)
        add_list_o(&l,&arr[i],sizeof(t_cliente),comp_in);
    to_array_list(&l,res,sizeof(t_cliente));

    it_arr(exp,res,4,sizeof(t_cliente),comp_cl,"(8)-> test_AddListO_Agregar5DosRepetidos_ConservaLaPrimerClave_ResultadoPass");
    clear_list(&l);
}

