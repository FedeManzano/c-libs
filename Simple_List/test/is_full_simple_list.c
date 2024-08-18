#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"

void test_EstaLLena_False_Resultado_Pass ()
{
    t_simple_list l;
    init_simple_list(&l);
    int exp = 0;
    int res = is_full_simple_list(&l) ? 1 : 0;
    it(&exp,&res,sizeof(int),comp_integer,"3 - test_EstaLLena_False_Resultado_Pass");
}

