#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"


void test_SubSimpleList_CrearSublistaDe5Elementos_Resultado_Pass()
{
    t_simple_list l;
    init_simple_list(&l);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l,&arr[i],sizeof(int));

    t_simple_list l2 = sub_simple_list(&l,sizeof(int),0,5);

    int res[5];

    to_array_simple_list(&l2,res,sizeof(int));

    for(int i = 0; i < len_simple_list(&l2); i ++)
    {
        int in;
        get_simple_list(&l2,&in,sizeof(int),i);
        printf("%d ", in);
    }

}
