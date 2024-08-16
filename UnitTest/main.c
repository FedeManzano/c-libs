#include <stdio.h>
#include <stdlib.h>
#include "it.h"


int comp_int_test(const void *e1, const void *e2 ){
    int *ele1 = (int *)e1;
    int *ele2 = (int *)e2;
    return *ele1 - *ele2;
}

int main()
{

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[15] = {1,2,3,4,5,6,7,8,9,10};


    it_arr(NULL,NULL,10,0,comp_int_test, "1- Test IT");
    it_arr(arr1,arr2,10,sizeof(int),comp_int_test, "2- Test IT");


    int num1 = 1;
    int num2 = 2;

    it(&num1,&num2,sizeof(int),comp_int_test,"3- Test IT");

    return 0;
}
