#include <stdio.h>
#include <stdlib.h>
#include <it.h>
#include <time.h>
#include "../list_g.h"
#include "../test_list_g.h"
#include "../comp_func.h"


void test_SortLinkList_OrdenarListaMoviendoEnlaces_ResultadoPass(){
    t_list l;
    init_list(&l);

    int exp[10000];
    int res[10000];


    for(int i = 0; i < 10000; i++){
        exp[i] = i + 1;
        res[i] = 10000 - i;
    }

    insert_range_list(&l,res,10000,sizeof(int),0);

    long ti = clock();
    sort_selection_list(&l,sizeof(int),comp_in);
    long tf = clock();


    to_array_list(&l,res,sizeof(int));

    for(int i = 0; i < 10000; i++)
        printf("%d ", res[i]);


    it_arr(exp,res,10000,sizeof(int),comp_in,"(34)-> test_SortLinkList_OrdenarListaMoviendoEnlaces_ResultadoPass");
    clear_list(&l);
    printf("Tiempo En ordenar: %ld",tf-ti);

}


void test_SortLinkList_ClientesVsEnteros_ResultadoPass(){
    t_list l;
    init_list(&l);

}


void test_SortLinkList_Productos_ResultadoPass(){
    t_list l;
    init_list(&l);

    t_producto exp[5000];
    t_producto p1;

    for(int i = 0; i < 5000; i++){

        p1.cod = 5000 - i;
        strcpy(p1.nombre,"Nombre");
        strcpy(p1.cat,"Cat");
        p1.stock = 10;
        p1.precio = 2700.22;

        exp[i] = p1;
    }

    insert_range_list(&l,exp,5000,sizeof(t_producto),0);

    long ti = clock();
    sort_selection_list(&l,sizeof(t_producto),comp_p);
    long tf = clock();


    clear_list(&l);
    printf("\n(35) -> test_SortLinkList_10000Productos_ResultadoPass -> Tiempo En ordenar: %ld",tf-ti);
}
