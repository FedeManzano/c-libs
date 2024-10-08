#ifndef TEST_SIMPLE_LIST_H_INCLUDED
#define TEST_SIMPLE_LIST_H_INCLUDED

#include "test_utils.h"

void test_EstaVacia_Verdadero_Resultado_Pass ();
void test_EstaVacia_False_Resultado_Pass ();
void test_EstaLLena_False_Resultado_Pass ();
void test_AddSimpleList_DiezElementos_Resultado_Pass();
void test_AddSimpleList_ListaNula_Resultado_Pass ();
void test_AddSimpleList_InfoNula_Resultado_Pass ();
void test_AddSimpleList_SizeMenorIgualCero_Resultado_Pass();
void test_AddSimpleList_TodosRepetidos_Resultado_Pass ();
void test_AddSimpleListInOrder_DiezElementos_Resultado_Pass ();
void test_AddSimpleListEnOrden_ListaNula_Resultado_Pass ();
void test_AddSimpleListEnOrden_InfoNula_Resultado_Pass ();
void test_AddSimpleListEnOrden_SizeMenorIgualCero_Resultado_Pass ();
void test_AddSimpleListEnOrden_TodosRepetidos_Resultado_Pass ();
void test_tryAddSimpleListInOrder_DiezElementos_Resultado_Pass ();
void test_TryAddSimpleListEnOrden_ListaNula_Resultado_Pass ();
void test_TryAddSimpleListEnOrden_InfoNula_Resultado_Pass ();
void test_TryAddSimpleListEnOrden_SizeMenorIgualCero_Resultado_Pass ();
void test_TryAddSimpleListEnOrden_TodosRepetidos_Resultado_Pass ();
void test_tryAddUpdateSimpleListInOrderUpdate_DiezElementos_Resultado_Pass ();
void test_TryAddSimpleListEnOrdenUpdate_ListaNula_Resultado_Pass ();
void test_TryAddSimpleListEnOrdenUpdate_InfoNula_Resultado_Pass ();
void test_TryAddSimpleListEnOrdenUpdate_SizeMenorIgualCero_Resultado_Pass ();
void test_TryAddSimpleListEnOrdenUpdate_TodosRepetidos_Resultado_Pass ();
void test_LenSinpleList_ListaVacia_Resultado_Pass () ;
void test_LenSinpleList_ListaNula_Resultado_Pass ();
void test_LenSinpleList_UnElemento_Resultado_Pass ();
void test_InsertSimpleList_InsertarElementoEnUnaListaVacia_Resultado_Pass ();
void test_InsertSimpleList_InsertarEnListaNula_Resultado_Pass ();
void test_InsertSimpleList_InsertarConInfoNula_Resultado_Pass ();
void test_InsertSimpleList_InsertarVariosElementos_Resultado_Pass ();
void test_InsertSimpleList_InsertarUnRangoDeElementos_Resultado_Pass ();
void test_InsertSimpleList_InsertarUnRangoDeElementosConIndexUno_Resultado_Pass ();
void test_SortSimpleList_OrdenarDiezElementos_Resultado_Pass();
void test_SortSimpleList_ListaNula_Resultado_Pass();
void test_SortSimpleList_TamMenorIgualACero_Resultado_Pass();
void test_DeleteSimpleList_EliminarElementoListaDeDiez_Resultado_Pass ();
void test_DeleteSimpleList_EliminarElementoDelFinal_Resultado_Pass ();
void test_DeleteSimpleList_EliminarElementoDelInicio_Resultado_Pass ();
void test_DeleteSimpleList_EliminarElementoYDuplicados_Resultado_Pass ();
void test_IndexOfSimpleList_IndexDeUnElementoDentro_Resultado_Pass ();
void test_IndexOfSimpleList_IndexDeUnNoEstaEnLaLista_Resultado_Pass ();
void test_IndexOfSimpleList_IndexDeListaNula_Resultado_Pass ();
void test_IndexOfSimpleList_IndexDeInfoNula_Resultado_Pass ();
void test_FindSimpleList_ElementoEncontrado_Resultado_Pass ();
void test_FindSimpleList_ElementoNoEncontrado_Resultado_Pass ();
void test_FilterSimpleList_NumerosPares_Resultado_Pass ();
void test_SubSimpleList_CrearSublistaDe5Elementos_Resultado_Pass();
void test_SubSimpleList_StartNegativo_Resultado_Pass();
void test_SubSimpleList_EndNegativo_Resultado_Pass();
void test_EqualsList_CompararDosListasIguales_Resultado_Pass();
void test_EqualsList_CompararDosListasDistintoElUltimo_Resultado_Pass();
void test_EqualsList_CompararDosListasDistintoElPrimero_Resultado_Pass();
void test_EqualsList_CompararDosListasDistintoTamano_Resultado_Pass();
void test_IntersectionSimpleList_InterseccionTresElementos_Resultado_Pass();
void test_IntersectionSimpleList_InterseccionNingunElemento_Resultado_Pass();
void test_SubstractSimpleList_RestaDeconjuntosEnLista();
void test_FileToSimpleList_CargarListaConNumerosEnteros_Resultado_Pass();
void test_FileToSimpleList_LlenarArchivoConEnteros_Resultado_Pass();




#endif // TEST_SIMPLE_LIST_H_INCLUDED
