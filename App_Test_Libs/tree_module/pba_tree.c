#include <stdio.h>
#include <stdlib.h>
#include "../libs/menu.h"
#include "../utils/utils.h"
#include "pba_tree.h"


void pba_mostrar_grafico_arbol (t_tree_set *t)
{
    show_graph_tree_set(t,dibujar,comp_in);
}


void mostrar_elemento_arbol(t_tree_set *t)
{
    limpiar_mostrar_titulo("Ingreso de elementos\n\n");
    pba_mostrar_grafico_arbol(t);
    printf("\n\n");
}

void pba_ingresar_elemento_arbol(t_tree_set *t)
{
    char op;
    do
    {

        mostrar_elemento_arbol(t);
        int val = ingresar_valor_entero("Ingrese el elemento( Entero): ");

        add_tree_set(t,&val,sizeof(int),comp_in);

        mostrar_elemento_arbol(t);

        op = seleccionar_opcion("Desea seguir agregando elementos (S/N): ");
    }
    while(op == 'S' || op == 's');
}


void pba_cantidad_nodos_arbol(t_tree_set *t)
{
    limpiar_mostrar_titulo("Cantidad de Nodos\n\n");
    show_graph_tree_set(t,dibujar,comp_in);
    printf("\n\nLa cantiad de elementos es: %d\n\n",count_tree_set(t));
    pausar();
}

void pba_altura_arbol(t_tree_set *t)
{
    limpiar_mostrar_titulo("Altura del Arbol\n\n");
    show_graph_tree_set(t,dibujar,comp_in);
    printf("\n\nLa altura es: %d\n\n",height_tree_set(t));
    pausar();
}

void pba_rec(t_tree_set *t, t_recorrido recorrido, char *mje)
{
    limpiar_mostrar_titulo(mje);
    show_graph_tree_set(t,dibujar,comp_in);
    printf("\n\n");
    recorrido(t,show_ele);
    printf("\n\n");
    pausar();
}

void pba_nivel_arbol(t_tree_set *t)
{
    limpiar_mostrar_titulo("Niveles del Arbol\n\n");
    show_graph_tree_set(t,dibujar,comp_in);
    printf("\n\nLos niveles del arbol: %d\n\n", level_tree_set(t));
    pausar();
}

void pba_niveles_info_arbol(t_tree_set *t)
{
    int cn = count_tree_set(t);

    if(!cn)
    {
        limpiar();
        printf("No hay elementos en el arbol\n\n");
        pausar();
        return;
    }

    char op;
    do
    {

        limpiar_mostrar_titulo("Niveles de la Informacion del Arbol\n\n");
        show_graph_tree_set(t,dibujar,comp_in);

        int val = ingresar_valor_entero("\nIngrese el valor que desea saber: ");

        printf("\n\nEl nivel de (%d) es -> %d\n\n", val,level_info_tree_set(t,&val,comp_in));

        op = seleccionar_opcion("Desea seguir calculando(S/N): ");
    }
    while(op == 'S' || op == 's');
}

void pba_un_nivel_completo(t_tree_set *t)
{
    int cn = count_tree_set(t);

    if(!cn)
    {
        limpiar();
        printf("No hay elementos en el arbol\n\n");
        pausar();
        return;
    }

    char op;
    do
    {

        limpiar_mostrar_titulo("Mostrar Un Nivel\n\n");
        show_graph_tree_set(t,dibujar,comp_in);

        int val = ingresar_valor_entero("\nIngrese el nivel a mostrar: ");

        if(val < 0 || val > level_tree_set(t))
        {
            printf("\n\nEl nivel no existe\n\n");
        }
        else
        {
            printf("\n\n");
            show_level_tree_set(t,val,show_ele);
            printf("\n\n");

        }
        op = seleccionar_opcion("Desea seguir calculando(S/N): ");

    }
    while(op == 'S' || op == 's');
}


void pba_eliminar_elemento(t_tree_set *t)
{
    int cn = count_tree_set(t);

    if(!cn)
    {
        limpiar();
        printf("No hay elementos en el arbol\n\n");
        pausar();
        return;
    }

    char op;
    do
    {

        limpiar_mostrar_titulo("Eliminar Elemento\n\n");
        show_graph_tree_set(t,dibujar,comp_in);

        int val = ingresar_valor_entero("\nIngrese elemento a eliminar: ");

        delete_tree_set(t,&val,sizeof(int),comp_in);

        limpiar_mostrar_titulo("Eliminar Elemento\n\n");
        show_graph_tree_set(t,dibujar,comp_in);

        printf("\n\n");

        op = seleccionar_opcion("Desea seguir eliminando elementos (S/N): ");

    }
    while(op == 'S' || op == 's');
}

void pba_mostrar_arbol(t_tree_set *t)
{
    limpiar();
    printf("Grafico del arbol\n\n");
    pba_mostrar_grafico_arbol(t);
    printf("\n\n");
    pausar();
}

void pba_mostrar_hojas(t_tree_set *t)
{
    limpiar();
    pba_mostrar_grafico_arbol(t);
    printf("\n\n");
    show_leaf_tree_set(t,show_ele);
    pausar();
}

void pba_podar_hojas(t_tree_set *t)
{
    int cn = count_tree_set(t);

    if(!cn)
    {
        limpiar();
        printf("No hay elementos en el arbol\n\n");
        pausar();
        return;
    }

    char p;
    do
    {

        limpiar_mostrar_titulo("Podar hojas del arbol\n\n");
        show_graph_tree_set(t,dibujar,comp_in);

        p = seleccionar_opcion("\ndesea podar el arbol(S/N): ");

        if(p == 's' || p == 'S')
            delete_left_tree_set(t);

        limpiar_mostrar_titulo("Podar hojas del arbol\n\n");
        show_graph_tree_set(t,dibujar,comp_in);

        printf("\n\n");

    }
    while( (p == 'S' || p == 's') && count_tree_set(t) > 0);
}


void pba_crear_index_archivo()
{
    limpiar();

    t_tree_set t;
    init_tree_set(&t);

    leer_archivo();

    FILE * arch = fopen("personas.dat", "rb");

    if(!arch)
        return;

    file_to_tree_set(&t,&arch,sizeof(t_ind),sizeof(t_persona),comp_ind,lectura);

    printf("\nGrafico Index\n\n");
    show_graph_tree_set(&t,dibujar_ind,comp_ind);

    printf("\n");
    pausar();
}
