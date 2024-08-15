#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_IsEmptyList_LaListaEstaVaciaResVerdadero_Resultado_Pass() {
    t_list l;
    init_list(&l);

    int exp = 1;
    int res = is_empty_list(&l) ? 1 : 0;

    it(&exp,&res,sizeof(int),comp_in,"(1)-> test_IsEmptyList_LaListaEstaVacia_Verdadero_Resultado_Pass");
}

void test_IsEmptyList_LaListaNoEstaVaciaResVerdadero_Resultado_Pass() {
    t_list l;
    init_list(&l);

    int elemento = 0;

    add_list(&l,&elemento,sizeof(int));

    int exp = 0;
    int res = is_empty_list(&l) ? 1 : 0;

    it(&exp,&res,sizeof(int),comp_in,"(2)-> test_IsEmptyList_LaListaNoEstaVacia_Verdadero_Resultado_Pass");
    clear_list(&l);
}


