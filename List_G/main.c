#include <stdio.h>
#include <stdlib.h>
#include "test_list_g.h"

int main()
{

    printf("TEST Unitarios de el TDA Lista Doblemente Enlazada\n\n");

    test_IsEmptyList_LaListaEstaVaciaResVerdadero_Resultado_Pass();
    test_IsEmptyList_LaListaNoEstaVaciaResVerdadero_Resultado_Pass();
    test_AddListO_ListaNula_MenosDiez_ResultadoPass();
    test_AddListO_InfoNula_MenosNueve_ResultadoPass();
    test_AddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass();
    test_AddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass();
    test_AddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass();
    test_AddListO_Agregar5DosRepetidos_ConservaLaPrimerClave_ResultadoPass();
    test_AddListTryListO_ListaNula_MenosDiez_ResultadoPass();
    test_TryAddListO_InfoNula_MenosNueve_ResultadoPass();
    test_TryAddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass();
    test_TryAddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass();
    test_TryAddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass();
    test_TryAddListO_Agregar5DosRepetidos_ConservaLaUltimaClave_ResultadoPass();
    test_AddFirstList_ListaNula_MenosDiez_ResultadoPass();
    test_AddFirstListO_InfoNula_MenosNueve_ResultadoPass();
    test_AddFirstList_Agregar5ElementosSinRepetir_CompPila_ResultadoPass();
    test_AddFirstList_Agregar5ElementosTodosRepetidos_SeMantienenTodos_ResultadoPass();
    test_AddFirstList_Agregar5DosRepetidos_OrdenInverso_ResultadoPass();
    test_AddList_ListaNula_MenosDiez_ResultadoPass();
    test_AddList_InfoNula_MenosNueve_ResultadoPass();
    test_AddFirstList_Agregar5ElementosSinRepetir_CompCola_ResultadoPass();
    test_AddList_Agregar5ElementosTodosRepetidos_SeMantienenTodos_ResultadoPass();
    test_InsertList_InsertarUnElementoAlInicio_Resultado_Pass ();
    test_InsertList_InsertarUnElementoAlFinal_Resultado_Pass ();
    test_InsertList_InsertarUnElementoEnLaPos2_Resultado_Pass ();
    test_InsertList_InsertarUnElementoEnLaPos1_Resultado_Pass ();
    test_InsertList_InsertarUnElementoEnLaPenultima_Resultado_Pass ();
    test_InsertList_InsertarelementosEnListaVacia_Resultado_Pass ();
    test_IndexOfList_BuscarIndexDeElementoExistente_resultado_Pass();
    test_IndexOfList_BuscarIndexDeElementoNoExistente_resultado_Pass();
    test_InsertRangeList_InsertaUnRangoDe5Elementos_Resultado_Pass();
    test_InsertRangeList_InsertaUnRangoDe2Elementos_Resultado_Pass();
    test_SortLinkList_OrdenarListaMoviendoEnlaces_ResultadoPass();
    ///test_SortLinkList_ClientesVsEnteros_ResultadoPass();
    test_SortLinkList_Productos_ResultadoPass();
    test_AddFilterList_FiltrarLosEnterosPares_ResultadoPass();
    return 0;
}
