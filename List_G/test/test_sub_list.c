#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include <time.h>
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_SubList_SubLista5Elementos_Resultado_Pass ()
{
    t_list l, sub;
    init_list(&l);
    init_list(&sub);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_list(&l,&arr[i],sizeof(int));

    sub = sub_list(&l,sizeof(int),0,4);
    int info;
    for(int i = 0; i < len_list(&sub); i++)
    {
        get_info_list(&sub,&info,sizeof(int),i);
        printf("%d ", info);
    }
}
