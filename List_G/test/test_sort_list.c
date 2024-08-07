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

    int arr[10] = {5,10,8,2,4,6,9,3,7,1};
    int exp[10] = {1,2,3,4,5,6,7,8,9,10};
    int res[10];


    insert_range_list(&l,arr,10,sizeof(int),0);

    sort_link_list(&l,comp_in);

    to_array_list(&l,res,sizeof(int));




    it_arr(exp,res,10,sizeof(int),comp_in, "(34)-> test_SortLinkList_OrdenarListaMoviendoEnlaces_ResultadoPass");

    for(int i = 0; i < 10; i ++)
        printf("%d ", res[i]);
    clear_list(&l);
}


void test_SortLinkList_ClientesVsEnteros_ResultadoPass(){

    printf("\n\ntest(35) - > Prueba de estres 20000 elementos\n");
    printf("Ordenar una estructura compleja y una simple\n");
    printf("El objetivo es que tarden lo mismo\n");



    t_list listaCliente;
    init_list(&listaCliente);

    t_list listaEntero;
    init_list(&listaEntero);

    int arr[10000];
    t_producto clientes[10000];



    for(int i = 0; i < 10000; i ++){
        arr[i] = 10000 - i;
    }
    t_producto a;

    for(int i = 0; i < 10000; i ++){
        a.cod = 10000 - i;
        strcpy(a.nombre,"Nombre");
        strcpy(a.nombre,"Categoria");
        a.tipo = 'C';
        a.precio = 100;
        a.stock = 10;
        clientes[i] = a;
    }


    insert_range_list(&listaEntero,arr,10000,sizeof(int),0);
    insert_range_list(&listaCliente,clientes,10000,sizeof(t_producto),0);

    long i = clock();
    sort_link_list(&listaEntero,comp_in);
    long f = clock();


    long ic = clock();
    sort_link_list(&listaCliente,comp_p);
    long fc = clock();

    printf("\n20000 Elementos Enteros: %ld vs Clientes: %ld" ,f-i,fc-ic);
}


void test_SortLinkList_Productos_ResultadoPass(){

    printf("\n\ntest(35) - > Prueba de estres 20000 elementos\n");
    printf("Ordenar una estructura compleja\n");
    printf("El objetivo es que tarden lo mismo\n");

    t_list l;
    init_list(&l);
    t_producto productos[10000];

    t_producto a;

    for(int i = 0; i < 10000; i ++){
        a.cod = 10000 - i;
        strcpy(a.nombre,"Nombre");
        strcpy(a.nombre,"Categoria");
        a.tipo = 'C';
        a.precio = 100;
        a.stock = 10;
        productos[i] = a;
    }


    insert_range_list(&l,productos,10000,sizeof(t_producto),0);


    long ic = clock();
    sort_link_list(&l,comp_p);
    long fc = clock();

    printf("\nProductos Tiempo: %ld" ,fc-ic);
}
