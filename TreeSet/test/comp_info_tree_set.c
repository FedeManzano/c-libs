#include "comp_info_tree_set.h"



void dibujar(const void  *info, const int niv) {
	int * in = (int *)info;
	int i;
	for(i = 0; i < niv; i ++)
		printf("      ");
	printf("[ %02d ]\n ", *in);
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
