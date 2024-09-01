#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include "../../bundle/it.h"


typedef struct {
    int clave;
    char valor[10];
}t_test_try_add;


int comp_test_try_add(const void *e1, const void *e2)
{
    t_test_try_add *ele1 = (t_test_try_add *)e1;
    t_test_try_add *ele2 = (t_test_try_add *)e2;
    return ele1->clave - ele2->clave;
}


void show_test_try_add(const void *e1)
{
    t_test_try_add *ele1 = (t_test_try_add *)e1;
    printf("%d %s\n", ele1->clave, ele1->valor);
}


void test_TryAddTreeSet_AgregarElementosConReemplazo_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    t_test_try_add arr[10] =
    {
        {1,"11111"},
        {2,"22222"},
        {3,"33333"},
        {4,"44444"},
        {5,"55555"},
        {1,"22222"},
        {7,"77777"},
        {8,"88888"},
        {9,"99999"},
        {10,"1010"},
    };

    t_test_try_add exp[9] =
    {
        {1,"22222"},
        {2,"22222"},
        {3,"33333"},
        {4,"44444"},
        {5,"55555"},
        {7,"77777"},
        {8,"88888"},
        {9,"99999"},
        {10,"1010"},
    };

    t_test_try_add res[9];

    for(int i = 0; i < 10; i ++)
        try_add_tree_set(&t,&arr[i],sizeof(t_test_try_add),comp_test_try_add);

    to_array_in_order(&t,res,sizeof(t_test_try_add));


    it_arr(exp,res,9,sizeof(t_test_try_add),comp_test_try_add,"(16) -> test_TryAddTreeSet_AgregarElementosConReemplazo_Resultado_Pass");
}


void test_TryAddTreeSet_AgregarElementosConReemplazoRepetidos_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    t_test_try_add arr[10] =
    {
        {1,"11111"},
        {1,"22222"},
        {1,"33333"},
        {1,"44444"},
        {1,"55555"},
        {1,"22222"},
        {1,"77777"},
        {1,"88888"},
        {1,"99999"},
        {1,"1010"},
    };

    t_test_try_add exp[1] =
    {
        {1,"1010"},
    };

    t_test_try_add res[1];

    for(int i = 0; i < 10; i ++)
        try_add_tree_set(&t,&arr[i],sizeof(t_test_try_add),comp_test_try_add);

    to_array_in_order(&t,res,sizeof(t_test_try_add));


    it_arr(exp,res,1,sizeof(t_test_try_add),comp_test_try_add,"(17) -> test_TryAddTreeSet_AgregarElementosConReemplazoRepetidos_Resultado_Pass");
}

