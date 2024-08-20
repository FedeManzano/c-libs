#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"



void bubble_sort(void *arr, const int ce, const size_t size, t_comp comp)
{
    if(!arr || ce <= 1 || size <= 0)
        return;

    for(int i = 0; i < ce; i ++)
    {
        for(int j = i + 1; j < ce; j ++)
        {
            if(comp(arr + i * size,arr + j * size) > 0)
            {
                void *aux = malloc(size);
                if(!aux)
                    return;
                memcpy(aux,arr + i * size, size);
                memcpy(arr + i * size, arr + j *size,size);
                memcpy(arr + j *size,aux,size);
                free(aux);
            }
        }
    }
}
