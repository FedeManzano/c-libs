#ifndef TEST_LIST_G_H_INCLUDED
#define TEST_LIST_G_H_INCLUDED


void test_IsEmptyList_LaListaEstaVaciaResVerdadero_Resultado_Pass();
void test_IsEmptyList_LaListaNoEstaVaciaResVerdadero_Resultado_Pass();
void test_AddListO_ListaNula_MenosDiez_ResultadoPass();
void test_AddListO_InfoNula_MenosNueve_ResultadoPass();
void test_AddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass();
void test_AddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass();
void test_AddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass();
void test_AddListO_Agregar5DosRepetidos_ConservaLaPrimerClave_ResultadoPass();
void test_AddListTryListO_ListaNula_MenosDiez_ResultadoPass();
void test_TryAddListO_InfoNula_MenosNueve_ResultadoPass();
void test_TryAddListO_Agregar5ElementosSinRepetir_ArregloOrdenado_ResultadoPass();
void test_TryAddListO_Agregar5ElementosTodosRepetidos_UnSoloElemento_ResultadoPass();
void test_TryAddListO_Agregar5DosRepetidos_CuatroElementos_ResultadoPass();
void test_TryAddListO_Agregar5DosRepetidos_ConservaLaUltimaClave_ResultadoPass();
void test_AddFirstList_ListaNula_MenosDiez_ResultadoPass();
void test_AddFirstListO_InfoNula_MenosNueve_ResultadoPass();
void test_AddFirstList_Agregar5ElementosSinRepetir_CompPila_ResultadoPass();
void test_AddFirstList_Agregar5ElementosTodosRepetidos_SeMantienenTodos_ResultadoPass();
void test_AddFirstList_Agregar5DosRepetidos_OrdenInverso_ResultadoPass();
void test_AddList_ListaNula_MenosDiez_ResultadoPass();
void test_AddList_InfoNula_MenosNueve_ResultadoPass();
void test_AddFirstList_Agregar5ElementosSinRepetir_CompCola_ResultadoPass();
void test_AddList_Agregar5ElementosTodosRepetidos_SeMantienenTodos_ResultadoPass();
void test_InsertList_InsertarUnElementoAlInicio_Resultado_Pass ();
void test_InsertList_InsertarUnElementoAlFinal_Resultado_Pass ();
void test_InsertList_InsertarUnElementoEnLaPos2_Resultado_Pass ();
void test_InsertList_InsertarUnElementoEnLaPos1_Resultado_Pass ();
void test_InsertList_InsertarUnElementoEnLaPenultima_Resultado_Pass ();
void test_InsertList_InsertarelementosEnListaVacia_Resultado_Pass ();
void test_IndexOfList_BuscarIndexDeElementoExistente_resultado_Pass();
void test_IndexOfList_BuscarIndexDeElementoNoExistente_resultado_Pass();
void test_InsertRangeList_InsertaUnRangoDe5Elementos_Resultado_Pass();
void test_InsertRangeList_InsertaUnRangoDe2Elementos_Resultado_Pass();
void test_SortLinkList_OrdenarListaMoviendoEnlaces_ResultadoPass();
void test_SortLinkList_ClientesVsEnteros_ResultadoPass();
void test_SortLinkList_Productos_ResultadoPass();
#endif // TEST_LIST_G_H_INCLUDED
