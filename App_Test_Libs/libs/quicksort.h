/**
* Función genérica de ordenamiento con el algoritmo quick sort.
*
* Funcion:
* void qs(void * arr, const int ce, const int tam, t_comp comp);
*
* @author Federico Manzano
*/



#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

typedef int ( *t_comp )(const void *, const void *);

/** \brief
 * Algoritmo de quicksort para ordenar arreglos de cualquier tipo
 * \param arr void* Arreglo que se quiere ordenar
 * \param ce const int cantidad de elementos del arreglo
 * \param tam const int tamaño del dato de tipo de dato
 * \param comp t_comp puntero a una función de comparacion
 * \return void
 *
 */
void qs(void * arr, const int ce, const size_t tam, t_comp comp);


#endif // QUICKSORT_H_INCLUDED
