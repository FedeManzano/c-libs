/**
    Test Unitarios y de integraci�n.

    Biblioteca con las funcionalidades b�sicas para realizar test unitarios
    y de integraci�n.
    La composici�n es de tres funciones que permiten comparar arreglos, elementos
    individuales e imprimir un mensaje con el estado del test.


    Funciones:

    void it_arr(const void *, const void *, const int, const int, t_comp comp, char *);
    void it(const void *, const void *, const int, t_comp, char *);
    void message(const char *,const char *);


    Aclaraci�n:

    Las funciones toman un valor esperado para la resoluci�n del test, luego,
    lo compara con el resultado de una determinada operaci�n que se desea probar. Si son iguales,
    entonces el test fue exitoso, caso contrario hubo una falla.

    Ejemplo:

    void test_OrdenarArregloDe5EnterosConQuickSort_RespuestaPass(){
        int expected [5] = {1,2,3,4,5};
        int result [5] = {5,4,3,2,1};

        qs(result, 5); // ordena el arreglo

        it_arr(expected,result, 5,sizeof(int), comp_integer,"1 - test_OrdenarArregloDe5EnterosConQuickSort_RespuestaPass");

    }
    Si la funci�n qs funciona corretamente los arreglos expected y result son iguales despues de la llamada a la funci�n.

    @author Federico Manzano
*/


#ifndef IT_H_INCLUDED
#define IT_H_INCLUDED

#include <string.h>

typedef int (*t_comp)(const void *, const void *);

/**
    Permite comparar arreglos de cualquier tipo y verificar si estos son iguales
    para corrobar el buen funcionamiento de la funci�n que se est� probando.
    Para realizar este proceso toma en uno de sus par�metros un *ptr a una funci�n de
    comparaci�n del tipo int (*t_comp)(const void *, const void *).

    @see pointerFn.h
*/
void it_arr(const void * expected, const void * result, const unsigned long ce, const size_t tam, t_comp comp, char * nameTest);


/**
    Permite comparar elementos de cualquier tipo y verificar si estos son iguales
    para corrobar el buen funcionamiento de la funci�n que se est� probando.
    Para realizar este proceso toma en uno de sus par�metros un *ptr a una funci�n de
    comparaci�n del tipo int (*t_comp)(const void *, const void *).

    @see pointerFn.h
*/
void it(const void *expected, const void *result, const size_t tam, t_comp comp, char * nameTest);


/**
    Muestra el resultado de la operaci�n con un mensaje PASS si el
    test fue exitoso. FAIL si fue fallido junto con una descripci�n.
*/
void message(const char *mes,const char * res);

#endif // IT_H_INCLUDED
