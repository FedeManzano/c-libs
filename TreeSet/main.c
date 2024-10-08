#include <stdio.h>
#include <stdlib.h>
#include "tree_set.h"
#include "test/test_tree_set.h"


int main()
{


    test_ArbolVacio_Verdadero_Resultado_Pass();
    test_ArbolNoVacio_Falso_Resultado_Pass ();
    test_PasarAArreglo_ArregloOrdenado_Resultado_Pass();
    test_AgregarElementos_UnSoloElementoPorRepetidos_Resultado_Pass();
    test_AgregarElementos_InfoNulaMenosNueve_Resultado_Pass ();
    test_AgregarElementos_TamDatoInvalidoMenosocho_Resultado_Pass ();
    test_BuscarEnArbol_BusquedaExitosa_ArregloDeInd_ResultadoPass();
    test_BuscarEnArbol_BusquedaFallida_ArregloDeInd_ResultadoPass();
    test_CantidadNodosArbol_ArbolDiezNodos_Resultado_Pass();
    test_CantidadNodosArbol_ArbolVacio_Resultado_Pass ();
    test_CantidadNodosArbol_ArbolNulo_Resultado_Pass();
    test_AlturaDelArbol_AlturaDistintaDeCero_Resultado_Pass();
    test_AlturaDelArbol_ArbolNulo_Resultado_Pass();
    test_NivelArbol_NievelDistintaDeCero_Resultado_Pass();
    test_NivelDelArbol_ArbolNulo_Resultado_Pass();
    test_ContarHojas_HojasDistintoCero_Resultado_Pass();
    test_ContarHojas_ArbolNulo_Resultado_Pass();
     test_Amplitude_Recorrido_Resultado_Pass();
    //test_Aplitude_RecorridoEnAlplitud_ResultadoPass ();
    test_TryAddTreeSet_AgregarElementosConReemplazo_Resultado_Pass();
    test_TryAddTreeSet_AgregarElementosConReemplazoRepetidos_Resultado_Pass();
    return 0;
}
