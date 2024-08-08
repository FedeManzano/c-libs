#include <stdio.h>
#include <stdlib.h>
#include "tree_set.h"
#include "test/test_tree_set.h"


int main()
{

    test_ArbolVacio_Verdadero_Resultado_Pass();
    test_ArbolNoVacio_Falso_Resultado_Pass ();
    test_PasarAArreglo_ArregloOrdenado_Resultado_Pass();
    return 0;
}
