#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_EqualsList_DosListadosIguales_Resultado_Pass()
{
    t_list l1,l2;

    init_list(&l1);
    init_list(&l2);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_list(&l1,&arr[i],sizeof(int));
    for(int i = 0; i < 10; i ++)
        add_list(&l2,&arr[i],sizeof(int));

    int exp = 1;
    int res = equals_list(&l1,&l2,comp_in);


    it(&exp,&res,sizeof(int),comp_in,"(37) -> test_EqualsList_DosListadosIguales_Resultado_Pass");
}


void test_EqualsList_DosListasMismoTamanoDistintoContenido_Resultado_Pass()
{
    t_list l1,l2;

    init_list(&l1);
    init_list(&l2);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_list(&l1,&arr[i],sizeof(int));
    arr[9] = 11;
    for(int i = 0; i < 10; i ++)
        add_list(&l2,&arr[i],sizeof(int));

    int exp = 0;
    int res = equals_list(&l1,&l2,comp_in);


    it(&exp,&res,sizeof(int),comp_in,"(38) -> test_EqualsList_DosListasMismoTamanoDistintoContenido_Resultado_Pass");
}



void test_EqualsList_DosListasMismoTamanoDiferenciaPrimerElemento_Resultado_Pass()
{
    t_list l1,l2;

    init_list(&l1);
    init_list(&l2);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        add_list(&l1,&arr[i],sizeof(int));
    arr[0] = 0;
    for(int i = 0; i < 10; i ++)
        add_list(&l2,&arr[i],sizeof(int));

    int exp = 0;
    int res = equals_list(&l1,&l2,comp_in);


    it(&exp,&res,sizeof(int),comp_in,"(39) -> test_EqualsList_DosListasMismoTamanoDiferenciaPrimerElemento_Resultado_Pass");
}
