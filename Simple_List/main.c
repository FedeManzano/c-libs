#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"
#include "test/test_simple_list.h"

int main()
{

    printf("TEST Para lista vacia\n");
    test_EstaVacia_Verdadero_Resultado_Pass();
    test_EstaVacia_False_Resultado_Pass ();

    printf("\nTEST Para lista llena\n");
    test_EstaLLena_False_Resultado_Pass();

    printf("\nTEST Para agregar elementos a lista\n");
    test_AddSimpleList_DiezElementos_Resultado_Pass();
    test_AddSimpleList_ListaNula_Resultado_Pass ();
    test_AddSimpleList_InfoNula_Resultado_Pass();
    test_AddSimpleList_SizeMenorIgualCero_Resultado_Pass();
    test_AddSimpleList_TodosRepetidos_Resultado_Pass();

    printf("\nTEST Para agregar elementos en orden a lista\n");
    test_AddSimpleListInOrder_DiezElementos_Resultado_Pass ();
    test_AddSimpleListEnOrden_ListaNula_Resultado_Pass();
    test_AddSimpleListEnOrden_InfoNula_Resultado_Pass();
    test_AddSimpleListEnOrden_SizeMenorIgualCero_Resultado_Pass();
    test_AddSimpleListEnOrden_TodosRepetidos_Resultado_Pass();

    printf("\nTEST Para agregar elementos en orden a lista con reemplazo\n");
    test_tryAddSimpleListInOrder_DiezElementos_Resultado_Pass ();
    test_TryAddSimpleListEnOrden_ListaNula_Resultado_Pass ();
    test_TryAddSimpleListEnOrden_InfoNula_Resultado_Pass();
    test_TryAddSimpleListEnOrden_SizeMenorIgualCero_Resultado_Pass();
    test_TryAddSimpleListEnOrden_TodosRepetidos_Resultado_Pass();

    printf("\nTEST Para agregar elementos en orden a lista con actualizacion\n");
    test_tryAddUpdateSimpleListInOrderUpdate_DiezElementos_Resultado_Pass();
    test_TryAddSimpleListEnOrdenUpdate_ListaNula_Resultado_Pass ();
    test_TryAddSimpleListEnOrdenUpdate_InfoNula_Resultado_Pass ();
    test_TryAddSimpleListEnOrdenUpdate_SizeMenorIgualCero_Resultado_Pass ();
    test_TryAddSimpleListEnOrdenUpdate_TodosRepetidos_Resultado_Pass ();


    printf("\nTEST Cantidad de elementos de la lista\n");
    test_LenSinpleList_ListaVacia_Resultado_Pass();
    test_LenSinpleList_ListaNula_Resultado_Pass();
    test_LenSinpleList_UnElemento_Resultado_Pass ();

    printf("\nTEST Insertar elemento en lista\n");
    test_InsertSimpleList_InsertarElementoEnUnaListaVacia_Resultado_Pass ();
    test_InsertSimpleList_InsertarEnListaNula_Resultado_Pass ();
    test_InsertSimpleList_InsertarConInfoNula_Resultado_Pass ();
    test_InsertSimpleList_InsertarVariosElementos_Resultado_Pass();
    test_InsertSimpleList_InsertarUnRangoDeElementos_Resultado_Pass ();
    test_InsertSimpleList_InsertarUnRangoDeElementosConIndexUno_Resultado_Pass ();

    printf("\nTEST Ordenar Lista\n");
    test_SortSimpleList_OrdenarDiezElementos_Resultado_Pass();
    test_SortSimpleList_ListaNula_Resultado_Pass();
    test_SortSimpleList_TamMenorIgualACero_Resultado_Pass();

    printf("\nTEST Eliminar elementos de la lista\n");
    test_DeleteSimpleList_EliminarElementoListaDeDiez_Resultado_Pass();
    test_DeleteSimpleList_EliminarElementoDelFinal_Resultado_Pass();
    test_DeleteSimpleList_EliminarElementoDelInicio_Resultado_Pass ();
    test_DeleteSimpleList_EliminarElementoYDuplicados_Resultado_Pass ();

    printf("\nTEST Indice de un elemento en la lista\n");
    test_IndexOfSimpleList_IndexDeUnElementoDentro_Resultado_Pass ();
    test_IndexOfSimpleList_IndexDeUnNoEstaEnLaLista_Resultado_Pass ();
    test_IndexOfSimpleList_IndexDeListaNula_Resultado_Pass();
    test_IndexOfSimpleList_IndexDeInfoNula_Resultado_Pass ();

    printf("\nTEST Encontrar elemento en lista\n");
    test_FindSimpleList_ElementoEncontrado_Resultado_Pass ();
    test_FindSimpleList_ElementoNoEncontrado_Resultado_Pass ();


    return 0;
}
