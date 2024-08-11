#include <stdio.h>
#include <stdlib.h>
#include "../libs/quicksort.h"
#include "../libs/selection_sort.h"
#include "../utils/utils.h"
#include "pba_sort.h"
#include <time.h>


int comp_i(const void  *e1, const void *e2)
{
    int * ele1 = (int *)e1;
    int * ele2 = (int *)e2;
    return *ele1 - *ele2;
}


void pba_ordenar_seleccion(t_sort ordenar, const char *mje) {

    int ce;

    limpiar();

    printf(mje);

    ce = ingresar_valor_entero("Ingrese la cantidad de elementos: ");

    int *arr = (int *)malloc(sizeof(int) * ce);

    if(!arr)
        return;

    cargar_arreglo(arr,ce);

    printf(mje);

    mostrar_arreglo(arr,ce);

    ordenar(arr,ce,sizeof(int),comp_i);

    printf("\n\nOrdenado\n");
    mostrar_arreglo(arr,ce);

    printf("\n\n");

    pausar();
}


void pba_qs_vs_sel () {

    int arr1[15000];
    int arr2[15000];

    for(int i = 0; i < 15000; i++){
        arr1[i] = 15000 - i;
        arr2[i] = 15000 - i;
    }
    limpiar();
    printf("Quick vs Selection\n\n");

    printf("Ordenar 15000 elementos enteros \n\n");

    long fqi = clock();
    qs(arr1,15000,sizeof(int), comp_i);
    long fqf = clock();


    long fsi = clock();
    selection_sort(arr2,15000,sizeof(int), comp_i);
    long fsf = clock();

    printf("Los tiempos son: Selection %ld ms vs Quicksort %ld ms\n\n", fsf - fsi, fqf-fqi);

    pausar();

}
