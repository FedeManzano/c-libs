#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"


int comp_int(const void *e1, const void *e2)
{
    int *ele1 = (int *)e1;
    int *ele2 = (int *)e2;
    return *ele1 - *ele2;
}


int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};


    bubble_sort(arr,10,sizeof(int),comp_int);


    for(int i = 0; i < 10; i ++)
        printf("%d ", arr[i]);

    return 0;
}
