#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bundle/it.h"
#include "./quicksort.h"

int comp_integer (const void *e1, const void *e2){
    int *ele1 = (int *)e1;
    int *ele2 = (int *)e2;
    return *ele1 - *ele2;
}

int comp_flo (const void *e1, const void *e2){
    float *ele1 = (float *)e1;
    float *ele2 = (float *)e2;
    return *ele1 > *ele2 ? 1 : *ele1 < *ele2 ? -1 : 0;
}

int comp_dou (const void *e1, const void *e2){
    double *ele1 = (double *)e1;
    double *ele2 = (double *)e2;
    return *ele1 > *ele2 ? 1 : *ele1 < *ele2 ? -1 : 0;
}

void test_OrdenarArregloDeEnteros_ResultadoPASS(){
    int expected[10] = {1,2,3,4,5,6,7,8,9,10};
    int result[10] = {10,9,8,7,6,5,4,3,2,1};

    qs(result,10,sizeof(int),comp_integer);

    it_arr(expected,result,10,sizeof(int),comp_integer,"1 - test_OrdenarArregloDeEnteros_ResultadoPASS");
}

void test_OrdenarArregloDeFloat_ResultadoPASS(){
    float expected[10] = {0.1,0.2,0.3,0.4,0.5};
    float result[10] = {0.5,0.4,0.3,0.2,0.1};

    qs(result,5,sizeof(float),comp_flo);

    it_arr(expected,result,5,sizeof(float),comp_flo,"2 - test_OrdenarArregloDeFloat_ResultadoPASS");
}

void test_OrdenarArregloDeDouble_ResultadoPASS(){
    double expected[10] = {0.1,0.2,0.3,0.4,0.5};
    double result[10] = {0.5,0.4,0.3,0.2,0.1};

    qs(result,5,sizeof(double),comp_dou);

    it_arr(expected,result,5,sizeof(double),comp_dou,"3 - test_OrdenarArregloDeDouble_ResultadoPASS");
}

void test_Estres15000Enteros_ResultadoPASS(){
    int expected[15000];
    int result[15000];

    for(int i = 0; i < 15000; i++){
        expected[i] = i + 1;
        result[i] = 15000 - i;
    }
    qs(result,15000,sizeof(int),comp_integer);

    it_arr(expected,result,15000,sizeof(int),comp_integer,"4 - test_Estres15000Enteros_ResultadoPASS");
}
