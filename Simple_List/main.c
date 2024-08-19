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

    return 0;
}
