#include "comp_info_tree_set.h"
#include <string.h>


void dibujar(const void  *info, const int niv) {
	int * in = (int *)info;
	int i;
	for(i = 0; i < niv; i ++)
		printf("      ");
	printf("[ %02d ]\n ", *in);
}

void dibujar_index(const void  *info, const int niv) {
	t_index * in = (t_index *)info;
	int i;
	for(i = 0; i < niv; i ++)
		printf("          ");
	printf("[ %02ld | %02d ]\n ", in->nro,in->info);
}

int comp_i(const void *e1, const void *e2){
    int *n1 = (int *)e1;
    int *n2 = (int *)e2;
    return *n1 - *n2;
}

void show_i(const void *e){
    int *n1 = (int *)e;
    printf("%d ", *n1);
}


int comp_ind(const void *e1, const void *e2){
    t_ind *n1 = (t_ind *)e1;
    t_ind *n2 = (t_ind *)e2;
    return n1->nro - n2->nro;
}

int comp_index(const void *e1, const void *e2){
    t_index *n1 = (t_index *)e1;
    t_index *n2 = (t_index *)e2;
    return n1->info - n2->info;
}

int comp_s(const void *e1, const void *e2){
    char *n1 = (char *)e1;
    char *n2 = (char *)e2;
    return strcmp(n1,n2);
}

void read_info(const void *info, const void *ia,const void *nro){
    int * infoArch = (int *)info;
    t_index * info_tree =(t_index *)ia;
    long * n = (long *)nro;

    info_tree->info = *infoArch;
    info_tree->nro = *n;
}
