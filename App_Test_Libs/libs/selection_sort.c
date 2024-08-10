#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./selection_sort.h"


/**
*  Iterates through the array looking for the index that points to the lowest value
*  @return men
*/
int minor_ele (void * arr, const int len, const size_t size,int ind, t_comp comp){
    if(!arr || len <= 1 || size <= 0 || ind < 0 )
        return -1;

    int men = ind;

    while(ind < len){
        if(comp(arr + ind*size, arr + men*size) < 0)
            men = ind;
        ind ++;
    }

    return men;
}


/**
* Alg. Selection sort generic by any types.
*/
void selection_sort(void * arr, const int len, const size_t size, t_comp comp )
{
    if(!arr || len <= 1 || size <= 0)
        return;

    int i =0;
    int men = 0;


    while(i < len){

        men = minor_ele(arr,len,size,i,comp);
        if(men == -1)
            return;
        if(men != i){
            void * aux = malloc(sizeof(size));
            if(aux){
                memcpy(aux, arr + i * size, size);
                memcpy(arr+i*size,arr + men*size, size);
                memcpy(arr + men* size, aux, size);
                free(aux);
            }
        }
        i++;
    }
}
