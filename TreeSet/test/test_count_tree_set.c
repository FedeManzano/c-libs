#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include <it.h>


void test_CantidadNodosArbol_ArbolDiezNodos_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int arr[10] = {5,2,7,3,6,10,8,9,4,1};

    for(int i = 0; i < 10; i ++)
        if(!is_full_tree_set(&t))
            add_tree_set(&t,&arr[i],sizeof(int),comp_i);

    int exp = 10;
    int res = count_tree_set(&t);

    it(&exp,&res,sizeof(int),comp_i,"(9)-> test_CantidadNodosArbol_ArbolDiezNodos_Resultado_Pass");
    clear_tree_set(&t);
}

void test_CantidadNodosArbol_ArbolVacio_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int exp = 0;
    int res = count_tree_set(&t);

    it(&exp,&res,sizeof(int),comp_i,"(10)-> test_CantidadNodosArbol_ArbolVacio_Resultado_Pass");
    clear_tree_set(&t);
}

void test_CantidadNodosArbol_ArbolNulo_Resultado_Pass ()
{
    t_tree_set t;
    init_tree_set(&t);

    int exp = -10;
    int res = count_tree_set(NULL);

    it(&exp,&res,sizeof(int),comp_i,"(11)-> test_CantidadNodosArbol_ArbolNulo_Resultado_Pass");
    clear_tree_set(&t);
}

