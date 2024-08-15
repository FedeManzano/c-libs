#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"
#include <time.h>
#include "../bundle/it.h"


int comp_integer (const void *e1, const void *e2){
    int *ele1 = (int *)e1;
    int *ele2 = (int *)e2;
    return *ele1 - *ele2;
}

void test_SelectionSortPrimerArrayNull_ResultadoFAIL() {


    it_arr(NULL, NULL, 10, sizeof(int), comp_integer,"1 - test_SelectionSortPrimerArrayNull_ResultadoFAIL");

}

void test_SelectionSortSegundoArrayNull_ResultadoFAIL() {

    int arr[2] = {0};
    it_arr(arr, NULL, 10, sizeof(int), comp_integer,"2 - test_SelectionSortSegundoArrayNull_ResultadoFAIL");
}

void test_SelectionSortCanElementosCero_ResultadoFAIL() {

    int arr[2] = {0};
    int arr2[2] = {0};
    it_arr(arr, arr2, 0, sizeof(int), comp_integer,"3 - test_SelectionSortCanElementosCero_ResultadoFAIL");
}

void test_SelectionSortTamCeroResultadoFAIL() {

    int arr[2] = {0};
    int arr2[2] = {0};
    it_arr(arr, arr2, 2, 0, comp_integer,"4 - test_SelectionSortTamCeroResultadoFAIL");
}

void test_SelectionSortOrdenDeArregloInversoResultadoPASS() {

    int expected[10] = {1,2,3,4,5,6,7,8,9,10};
    int result[10] = {10,9,8,7,6,5,4,3,2,1};

    selection_sort(result,10,sizeof(int),comp_integer);

    it_arr(expected, result, 10, sizeof(int), comp_integer,"5 - test_SelectionSortOrdenDeArregloInversoResultadoPASS");
}

void test_SelectionSortEstresCon100000ElementosInveersosPASS(){
    int expected[100000];
    int result[100000];

    clock_t tiempo_inicio, tiempo_final;

    for(int i = 0; i < 100000; i ++)
    {
        expected[i] = i + 1;
        result[i] = 100000 - i;
    }

    tiempo_inicio = clock();
    selection_sort(result,100000,sizeof(int),comp_integer);
    tiempo_final = clock();

    it_arr(expected, result, 100000, sizeof(int), comp_integer,"6 - test_SelectionSortEstresCon100000ElementosInversosPASS");
    printf("Time: %ld ms\n", (tiempo_final - tiempo_inicio));
}

