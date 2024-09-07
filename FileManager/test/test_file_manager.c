#include <stdio.h>
#include <stdlib.h>
#include "../../bundle/it.h"
#include "../file_manager.h"

int comp_int(const void *e1, const void *e2)
{
    int *ele1 = (int *)e1;
    int *ele2 = (int *)e2;
    return *ele1 - *ele2;
}

void format_file(const void *e)
{
    int *ele = (int *)e;
    printf("%d ", *ele);
}

void crear_archivo_test()
{
    FILE * enteros;
    open_file_(&enteros,"enteros.dat","wb");
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i ++)
        fwrite(&arr[i],sizeof(int),1,enteros);
    fclose(enteros);
}

void test_OpenFile_AperturaYCreacionDeArchivos_Resultado_Pass ()
{
    FILE *arch_test;

    int exp = 1;
    int res = open_file_(&arch_test,"test_1.dat","wb");

    it(&exp,&res,sizeof(int),comp_int,"(1) -> test_OpenFile_AperturaYCreacionDeArchivos_Resultado_Pass");
    fclose(arch_test);
}

void test_OpenFile_AperturaIncorrectaArchivoInexistente_Resultado_Pass ()
{

    FILE *arch_test;

    int exp = 0;
    int res = open_file_(&arch_test,"test_2.dat","rb");

    it(&exp,&res,sizeof(int),comp_int,"(2) -> test_OpenFile_AperturaIncorrectaArchivoInexistente_Resultado_Pass");
    fclose(arch_test);
}

void test_OpenFile_MostrarArchivoBinario_Resultado_Pass ()
{
    crear_archivo_test();
    show_file("enteros.dat",format_file,sizeof(int));
    FILE *enteros = open_file("enteros.dat","rb");

    int exp = 10;
    int res = file_records_(&enteros,sizeof(int));

    it(&exp,&res,sizeof(int),comp_int,"(3) -> test_OpenFile_MostrarArchivoBinario_Resultado_Pass");
    file_close(&enteros);
}

