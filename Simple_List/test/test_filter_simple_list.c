#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"

void test_FilterSimpleList_NumerosPares_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int exp[5] = {2,4,6,8,10};
    int res[5];
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l,&arr[i],sizeof(int));

    t_simple_list lfil = filter_simple_list(&l,sizeof(int),fil);

    to_array_simple_list(&lfil,res,sizeof(int));

    it_arr(exp,res,5,sizeof(int),comp_integer,"46 - test_FilterSimpleList_NumerosPares_Resultado_Pass");

    clear_simple_list(&l);
    clear_simple_list(&lfil);
}
