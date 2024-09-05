#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_IntersectionList_TresElementosEnComun_Resultado_Pass()
{
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[3] = {5,8,10};


    t_list l1,l2;
    init_list(&l1);
    init_list(&l2);

    for(int i = 0; i < 10; i ++)
        add_list(&l1,&arr1[i],sizeof(int));
    for(int i = 0; i < 3; i ++)
        add_list(&l2,&arr2[i],sizeof(int));

    t_list res = intersection_list(&l1,&l2,sizeof(int),comp_in);

    int exp[3] = {5,8,10};
    int re[3];

    to_array_list(&res,re,sizeof(int));

    it_arr(exp,re,3,sizeof(int),comp_in,"(40) -> test_IntersectionList_TresElementosEnComun_Resultado_Pass");
    clear_list(&l1);
    clear_list(&l2);
    free(res);
}


void test_IntersectionList_SinElementosEnComun_Resultado_Pass()
{
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[3] = {100,200,300};


    t_list l1,l2;

    init_list(&l1);
    init_list(&l2);

    for(int i = 0; i < 10; i ++)
        add_list(&l1,&arr1[i],sizeof(int));
    for(int i = 0; i < 3; i ++)
        add_list(&l2,&arr2[i],sizeof(int));



    t_list res = intersection_list(&l1,&l2,sizeof(int),comp_in);

    int exp = 0;
    int re = len_list(&res);

    it(&exp,&re,sizeof(int),comp_in,"(41) -> test_IntersectionList_SinElementosEnComun_Resultado_Pass");
    clear_list(&l1);
    clear_list(&l2);
    free(res);
}
