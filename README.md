# Bibliotecas en lenguaje C

Algunos TDA para aprender programación e C.

- Algoritmos de ordenamiento
- Lista doblemnte enlazada
- Pila
- Cola
- Arbol binario
- TDA menú
- Fechas
- Test unitarios

## Cabeceras

### Algoritmos de ordenammiento

#### Quick Sort
```c
/**
* Función genérica de ordenamiento con el algoritmo quick sort.
*
* Funcion:
* void qs(void * arr, const int ce, const int tam, t_comp comp);
*
* @author Federico Manzano
*/
```

### Lista doblemente enlazada

```c

/**
*   TDA Lista doblemente enlazada genérica.
*
*   Se puede utilizar para gestionar cualquier tipo de dato
*   utilizando void * para abstraer la lógica de la lista y que
*   pueda ser reutilizada.
*
*   void init_list(t_list * l);
*   int is_empty_list(const t_list *l);
*   int is_full_list(const t_list * l);
*   int len_list(t_list *l);
*   int add_first_list(t_list *l, const void *info, const int tam);
*   int add_list(t_list *l, const void *info, const int tam);
*   int add_list_o(t_list *l, const void *info,const int tam, t_comp comp);
*   int try_add_list_o(t_list *l,const void *info,const int tam, t_comp comp);
*   int get_key_list(t_list *l, void *info,const int tam, t_comp comp);
*   int get_key_last_list(t_list *l, void *info,const int tam, t_comp comp);
*   void * get_info_list(t_list *l,void *info,const int tam,const int index);
*   int delete_list(t_list *l, void *info,const int tam, t_comp comp);
*   int delete_all_list(t_list *l, void *info,const int tam, t_comp comp);
*   void sort_list(t_list *l,const int tam, t_comp comp);
*   void sort_link_list(t_list *l, t_comp comp);
*   int insert_list(t_list *l,const void * info,const int tam, const int index);
*   void clear_list(t_list *l);
*   int to_array_list(t_list *l, void *arr, int tam);
*
*   Advertencia:
*
*   Esto es un TDA genérico, esto implica que la resposabilidad
*   de los tipos de datos ingresados a la lista es del usuario
*   que la utiliza.
*   Si ingresan a la misma lista varios tipos de datos y después
*   se producen errores, me desentiendo de la resposabilidad.
*
*
*   @author Federico Manzano (https://github.com/FedeManzano)
*/
```

### Pila dinámica

```c
/**
*   TDA Pila
*
*   Pila gen�rica para almacenar cualquier tipo de dato.
*   El puntero a la informaci�n, en la estructura, es de tipo
*   (void *).
*
*   ADV: Queda suje a la responsabilidad del usuario que no se ingresen varios
*   tipos de datos al mismo tiempo en la pila. Si esto sucede el funcionamiento
*   dar� errores.
*
*   @author Federico Mazano (https://github.com/FedeManzano)
*/

```


