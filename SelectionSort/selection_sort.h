/**
    Algoritmo Selection Sort

    Algoritmo de ordenamiento de selección
    CC: n^2

    Ejemplo
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};

    selection_sort(arr,10,sizeof(int),comp_int);

    mostrar_arreglo(arr);

    Resultado:

    [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]

    @author Federico Manzano (https://github.com/FedeManzano)

*/


#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

typedef int (*t_comp)(const void *, const void *);



/** \brief
 *  Algoritmo de ordenamiento por selección.

 * \param arr void* Puntero al arreglo a ordenar
 * \param len const int Tamaño del arreglo Por Ej: 10 elementos
 * \param size const size_t Tamaño del tipo de dato del arreglo pro Ej: sizeof(int)
 * \param comp t_comp Puntero a la función de comparación.
 * \return void
 *
 */
void selection_sort(void * arr, const int len, const size_t size, t_comp comp );


#endif // SELECTION_H_INCLUDED
