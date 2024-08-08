#include <stdio.h>
#include <stdlib.h>
#include "../tree_set.h"
#include "test_tree_set.h"
#include "comp_info_tree_set.h"
#include <it.h>


void test_BuscarEnArbol_BusquedaExitosa_ArregloDeInd_ResultadoPass()
{
    t_ind inds[5] = {
        {3,"30222555"},
        {5,"32595830"},
        {1,"25444666"},
        {4,"14555666"},
        {2,"41222333"},
    };

    t_tree_set t;
    init_tree_set(&t);

    for(int i = 0; i < 5; i ++)
        add_tree_set(&t,&inds[i],sizeof(t_ind),comp_ind);


    t_ind exp = {1,"25444666"};

    t_ind res;
    res.nro = 1;
    find_tree_set(&t,&res,sizeof(t_ind),comp_ind);

    it(exp.dni,res.dni,sizeof(exp.dni),comp_s,"(7)-> test_BuscarEnArbol_BusquedaExitosa_ArregloDeInd_ResultadoPass");
}

void crearArchPrueba() {
	FILE * arch = fopen("prueba.dat", "wb");
	int valor = 1;

	while(valor <= 20) {
		fwrite(&valor, sizeof(int), 1, arch);
		valor ++;
	}
	fclose(arch);
}

void test_BuscarEnArbol_BusquedaFallida_ArregloDeInd_ResultadoPass()
{
    t_ind inds[5] = {
        {3,"30222555"},
        {5,"32595830"},
        {1,"25444666"},
        {4,"14555666"},
        {2,"41222333"},
    };

    t_tree_set t;
    init_tree_set(&t);

    for(int i = 0; i < 5; i ++)
        add_tree_set(&t,&inds[i],sizeof(t_ind),comp_ind);


    int exp = 0;

    t_ind ind;
    ind.nro = 10;
    int res = find_tree_set(&t,&ind,sizeof(t_ind),comp_ind);


    it(&exp,&res,sizeof(int),comp_i,"(8)-> test_BuscarEnArbol_BusquedaFallida_ArregloDeInd_ResultadoPass");
}

void test_archArbol(){
    crearArchPrueba();

    FILE *arch = fopen("prueba.dat", "rb");

	if(!arch)
		return ;

    t_tree_set t;

    init_tree_set(&t);

    t_index in;
    file_binary_to_tree_set(&t,&arch,&in,sizeof(t_index),sizeof(int),comp_index,read_info);
    show_graph_tree_set(&t,&t,dibujar_index,comp_i);
}
