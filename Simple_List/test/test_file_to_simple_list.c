#include <stdio.h>
#include <stdlib.h>
#include "../simple_list.h"
#include "../../bundle/it.h"
#include "test_simple_list.h"

void cargar_archivo()
{
    FILE *arch = fopen("enteros.dat", "wb");

    int arr [10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i ++)
        fwrite(&arr[i],sizeof(int),1,arch);
    fclose(arch);
}

void test_FileToSimpleList_CargarListaConNumerosEnteros_Resultado_Pass()
{
    cargar_archivo();
    t_simple_list l;
    init_simple_list(&l);

    file_to_simple_list(&l,"enteros.dat",sizeof(int));

    int exp[10]= {1,2,3,4,5,6,7,8,9,10};
    int res[10];

    to_array_simple_list(&l,res,sizeof(int));

    it_arr(exp,res,10,sizeof(int),comp_integer,"57 - test_FileToSimpleList_CargarListaConNumerosEnteros_Resultado_Pass");
}


void test_FileToSimpleList_LlenarArchivoConEnteros_Resultado_Pass()
{
    cargar_archivo();
    t_simple_list l,res;
    init_simple_list(&l);
    init_simple_list(&res);

    for(int i = 0; i < 10; i ++)
        add_simple_list(&l,&i,sizeof(int));


    simple_list_to_file(&l,"enterosDos.dat",sizeof(int));
    file_to_simple_list(&res,"enterosDos.dat",sizeof(int));

    int exp[10]={0,1,2,3,4,5,6,7,8,9};
    int re[10];

    to_array_simple_list(&l,re,sizeof(int));

    it_arr(exp,re,10,sizeof(int),comp_integer,"58 - test_FileToSimpleList_LlenarArchivoConEnteros_Resultado_Pass");
}
