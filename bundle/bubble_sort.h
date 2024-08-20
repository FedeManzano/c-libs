/**
  Algoritmo de ordenamiento de la burbuja.

  Funciones:

  void bubble_sort(void *arr, const int ce, const size_t size, t_comp comp);

  Alboritmo de ordenamiento Bubble Sort.

  @author Federico Manzano (https://github.com/FedeManzano)
*/


#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED

typedef int (*t_comp)(const void *,const void *);

void bubble_sort(void *arr, const int ce, const size_t size, t_comp comp);


#endif // BUBBLE_SORT_H_INCLUDED
