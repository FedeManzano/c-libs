#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./quicksort.h"



void qsort_r(void * arr,int ini, int fin, const size_t tam, t_comp comp){

    int i = ini;
    int j = fin;

    void * pivote = malloc(tam);
    memcpy(pivote, arr + i*tam, tam);

    while(i < j){

        while(comp(pivote, arr + i*tam) >= 0 && i < j)
            i ++;
        while(comp(pivote, arr + j*tam) < 0 )
            j --;
        if(i < j)
        {
            void * aux = malloc(tam);
            memcpy(aux, arr + i*tam,tam);
            memcpy(arr + i*tam, arr + j*tam,tam);
            memcpy(arr + j *tam, aux,tam);
            free(aux);
        }
    }

    memcpy(arr + ini*tam, arr + j*tam,tam);
    memcpy(arr + j*tam, pivote, tam);

    free(pivote);

    if(ini < j - 1)
        qsort_r(arr,ini, j-1,tam,comp);
    if(j + 1 < fin)
        qsort_r(arr,j+1,fin, tam,comp);
}

void qs(void * arr, const int ce, const size_t tam, t_comp comp){
     if(!arr || ce <= 1 || tam <= 0)
        return;
    qsort_r(arr,0,ce-1,tam,comp);
}
