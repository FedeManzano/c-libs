#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./testSelection.h"

int main()
{
    clock_t tiempo_inicio, tiempo_final;

    tiempo_inicio = clock();
    test_SelectionSortPrimerArrayNull_ResultadoFAIL();
    test_SelectionSortSegundoArrayNull_ResultadoFAIL();
    test_SelectionSortCanElementosCero_ResultadoFAIL();
    test_SelectionSortTamCeroResultadoFAIL();
    test_SelectionSortOrdenDeArregloInversoResultadoPASS();
    test_SelectionSortEstresCon100000ElementosInveersosPASS();
    tiempo_final = clock();


    printf("\n\n Tiempo de ejecucion del test de integracion %ld ms", tiempo_final - tiempo_inicio);

    return 0;
}
