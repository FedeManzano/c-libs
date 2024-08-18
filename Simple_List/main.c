#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"
#include "test/test_simple_list.h"


int comp_i(const void *e1, const void *e2)
{
    int * ele1 = (int *)e1;
    int * ele2 = (int *)e2;

    return *ele1 - *ele2;
}

void up(void *info_list, void *info_u)
{
    int * il = (int *)info_list;
    int * iu = (int *)info_u;
    *il += *iu;
    printf("%d Update\n", *il);
}

int main()
{

    test_EstaVacia_Verdadero_Resultado_Pass();
    test_EstaVacia_False_Resultado_Pass ();

    return 0;
}
