#include <stdio.h>
#include <stdlib.h>
#include "../libs/date.h"
#include "../libs/menu.h"
#include "../utils/utils.h"
#include "pba_tree.h"


void dibujar(const void  *info, const int niv)
{
    int * in = (int *)info; // La info va a depender de que haya guardado en el árbol
    int i;
    for(i = 0; i < niv; i ++)
        printf("      ");
    printf("[ %02d ]\n ", *in);
}


int comp_in(const void  *e1, const void *e2)
{
   int * ele1 = (int *)e1;
   int * ele2 = (int *)e2;
   return *ele1 - *ele2;
}

void pba_mostrar_grafico_arbol (t_tree_set *t)
{
    show_graph_tree_set(t,dibujar,comp_in);
}


void mostrar_elemento_arbol(t_tree_set *t){
    limpiar_mostrar_titulo("Ingreso de elementos\n\n");
    pba_mostrar_grafico_arbol(t);
    printf("\n\n");
}

void pba_ingresar_elemento_arbol(t_tree_set *t)
{
    char op;
    do {

        mostrar_elemento_arbol(t);
        int val = ingresar_valor_entero("Ingrese el elemento( Entero): ");

        add_tree_set(t,&val,sizeof(int),comp_in);

        mostrar_elemento_arbol(t);

        op = seleccionar_opcion("Desea seguir agregando elementos (S/N): ");
    }while(op == 'S' || op == 's');
}
