#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void dibujar(const void  *info, const int niv)
{
    int * in = (int *)info; // La info va a depender de que haya guardado en el árbol
    int i;
    for(i = 0; i < niv; i ++)
        printf("      ");
    printf("[ %02d ]\n ", *in);
}


void dibujar_ind(const void  *info, const int niv)
{
    t_ind * in = (t_ind *)info; // La info va a depender de que haya guardado en el árbol
    int i;
    for(i = 0; i < niv; i ++)
        printf("                 ");
    printf("[ %02ld | %ld ]\n ", in->nro, in->dni);
}


int comp_in(const void  *e1, const void *e2)
{
    int * ele1 = (int *)e1;
    int * ele2 = (int *)e2;
    return *ele1 - *ele2;
}


int comp_ind(const void  *e1, const void *e2)
{
    t_ind * ele1 = (t_ind *)e1;
    t_ind * ele2 = (t_ind *)e2;
    return ele1->dni - ele2->dni;
}



void lectura(const void *info_arbol, const void *info_arch, const long nreg)
{
    t_ind * ia = (t_ind *)info_arbol; // Info del árbol a cargar
    t_persona *ifile = (t_persona *)info_arch; // info del archivo

    ia->dni = ifile->dni; // carga la clave del registro del archivo
    ia->nro = nreg; // carga el número de registro correpondiente a la posición en el archivo
}


void show_ele(const void * ele)
{
    int * elemento = (int *)ele;
    printf("%d ", *elemento);
}


void leer_archivo()
{

    FILE * arch = fopen("personas.dat", "rb");

    t_persona p;

    printf("Archivo Personas\n");

    fread(&p,sizeof(t_persona),1,arch);

    while(!feof(arch))
    {
        printf("%ld - %s\n", p.dni,p.apyn);
        fread(&p,sizeof(t_persona),1,arch);
    }

    fclose(arch);
}


void crear_archivo_prueba()
{
    t_persona p[10] =
    {
        {15222111, "federico"},
        {16555444, "marcos"},
        {17444888, "sebastian"},
        {18444555, "pedro"},
        {20222111, "luis"},
        {21555444, "felipo"},
        {25999999, "saul"},
        {26444555, "teresa"},
        {30222111, "marta"},
        {32111444, "carla"},

    };

    FILE * arch = fopen("personas.dat", "wb");

    fwrite(p,sizeof(p),1,arch);
    fclose(arch);
}

