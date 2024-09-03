#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_SubstractSimpleList_RestaDeconjuntosEnLista()
{
    t_simple_list l1, l2;

    init_simple_list(&l1);
    init_simple_list(&l2);

    int arr[10] = {1,5,10,15,20,25,30,35,40,45};
    int arr2[5] = {45,10,15,20,105};

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l1, &arr[i],sizeof(int));

    for(int i = 0; i < 5; i ++)
        add_simple_list(&l2, &arr2[i],sizeof(int));


    t_simple_list res = subtract_simple_list(&l1,&l2,sizeof(int),comp_integer);

    int info;

    for(int i = 0; i < len_simple_list(&res); i ++)
    {
        get_simple_list(&res,&info,sizeof(int),i);
        printf("%d ",info);
    }
}
